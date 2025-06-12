class Solution {
public:
    vector<vector<int>> dp;

    int func(int si, int ei, vector<int>& cuts) {
        if (si > ei) return 0;
        if (dp[si][ei] != -1) return dp[si][ei];

        int ans = INT_MAX;
        for (int i = si; i <= ei; ++i) {
            int cost = cuts[ei + 1] - cuts[si - 1];
            ans = min(ans, func(si, i - 1, cuts) + func(i + 1, ei, cuts) + cost);
        }

        return dp[si][ei] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        dp = vector<vector<int>>(m, vector<int>(m, -1));

        return func(1, m - 2, cuts);
    }
};
