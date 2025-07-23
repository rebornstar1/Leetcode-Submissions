class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        int groupSize = n / k;
        int totalMask = 1 << n;
        vector<int> dp(totalMask, INT_MAX);
        unordered_map<int, int> validGroup;

        for (int mask = 0; mask < totalMask; ++mask) {
            if (__builtin_popcount(mask) != groupSize) continue;
            unordered_set<int> seen;
            int maxVal = INT_MIN, minVal = INT_MAX;
            bool valid = true;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    if (seen.count(nums[i])) {
                        valid = false;
                        break;
                    }
                    seen.insert(nums[i]);
                    maxVal = max(maxVal, nums[i]);
                    minVal = min(minVal, nums[i]);
                }
            }

            if (valid) {
                validGroup[mask] = maxVal - minVal;
            }
        }

        dp[0] = 0;
        for (int mask = 0; mask < totalMask; ++mask) {
            if (dp[mask] == INT_MAX) continue;
            int unusedBits = ((1 << n) - 1) ^ mask;

            for (auto &[groupMask, incompat] : validGroup) {
                if ((mask & groupMask) == 0) {
                    int newMask = mask | groupMask;
                    dp[newMask] = min(dp[newMask], dp[mask] + incompat);
                }
            }
        }

        return dp[totalMask - 1] == INT_MAX ? -1 : dp[totalMask - 1];
    }
};
