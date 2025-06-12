class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;
        vector<int> a, b;
        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) a.push_back(nums[i]);
            else b.push_back(nums[i]);
            totalSum += nums[i];
        }

        vector<vector<int>> dpa(half + 1), dpb(half + 1);
        dpa[0].push_back(0);
        dpb[0].push_back(0);

        for (int i = 0; i < a.size(); i++) {
            for (int j = half; j >= 1; j--) {
                for (int val : dpa[j - 1]) {
                    dpa[j].push_back(val + a[i]);
                }
            }
        }

        for (int i = 0; i < b.size(); i++) {
            for (int j = half; j >= 1; j--) {
                for (int val : dpb[j - 1]) {
                    dpb[j].push_back(val + b[i]);
                }
            }
        }

        int ans = INT_MAX;

        for (int i = 0; i <= half; i++) {
            int j = half - i;
            if (j < 0 || j > half) continue;

            sort(dpb[j].begin(), dpb[j].end()); 

            for (int sa : dpa[i]) {
                int target = totalSum / 2 - sa;
                const auto& vec = dpb[j];

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    int sumB = *it;
                    int tempSum = sa + sumB;
                    ans = min(ans, abs(totalSum - 2 * tempSum));
                }

                if (it != vec.begin()) {
                    --it;
                    int sumB = *it;
                    int tempSum = sa + sumB;
                    ans = min(ans, abs(totalSum - 2 * tempSum));
                }
            }
        }

        return ans;
    }
};
