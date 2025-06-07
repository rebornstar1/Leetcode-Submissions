class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> minLen(n, INT_MAX);

        // 1. First pass (left to right): Track min length ending at or before i
        int left = 0, sum = 0, best = INT_MAX;
        for (int right = 0; right < n; ++right) {
            sum += arr[right];

            while (sum > target) sum -= arr[left++];

            if (sum == target) {
                int len = right - left + 1;
                best = min(best, len);
                minLen[right] = len;
            }

            if (right > 0)
                minLen[right] = min(minLen[right], minLen[right - 1]);
        }

        // 2. Second pass (right to left): Try to combine with left
        int res = INT_MAX;
        left = n - 1;
        sum = 0;
        best = INT_MAX;

        for (int right = n - 1; right >= 0; --right) {
            sum += arr[right];

            while (sum > target) sum -= arr[left--];

            if (sum == target) {
                int len = left - right + 1;
                if (right > 0 && minLen[right - 1] != INT_MAX)
                    res = min(res, len + minLen[right - 1]);
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};
