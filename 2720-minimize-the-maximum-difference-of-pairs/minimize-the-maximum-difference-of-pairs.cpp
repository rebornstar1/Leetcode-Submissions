class Solution {
public:
    // Function to count maximum number of non-overlapping pairs with diff <= m
    int func(vector<int>& nums, int m) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n - 1; ) {
            if (abs(nums[i] - nums[i + 1]) <= m) {
                cnt++;
                i += 2; // Skip the used pair
            } else {
                i++;
            }
        }
        return cnt;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int s = 0, e = nums.back() - nums.front();
        int ans = e;

        while (s <= e) {
            int m = s + (e - s) / 2;
            if (func(nums, m) >= p) {
                ans = m;   // Valid, try to minimize further
                e = m - 1;
            } else {
                s = m + 1;
            }
        }

        return ans;
    }
};
