class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for (char c : word) freq[c - 'a']++;

        vector<int> nonZeroFreq;
        for (int f : freq)
            if (f != 0) nonZeroFreq.push_back(f);

        sort(nonZeroFreq.begin(), nonZeroFreq.end());
        int n = nonZeroFreq.size();
        vector<long long> prefixSum(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefixSum[i + 1] = prefixSum[i] + nonZeroFreq[i];

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int maxFreqAllowed = nonZeroFreq[i] + k;

            // Find the first index j such that freq[j] > maxFreqAllowed
            int j = upper_bound(nonZeroFreq.begin(), nonZeroFreq.end(), maxFreqAllowed) - nonZeroFreq.begin();

            long long deleteLow = prefixSum[i]; // delete all freq < freq[i]
            long long deleteHigh = (prefixSum[n] - prefixSum[j]) - 1LL * (n - j) * maxFreqAllowed;

            ans = min(ans, (int)(deleteLow + deleteHigh));
        }

        return ans;
    }
};
