class Solution {
public:
    int climbStairs(int n) {
        vector<long long>dp(55,0);
        dp[0] = 1;
        for(int i = 0 ; i < 50 ; i++ )
        {
            dp[i+1]+=dp[i];
            dp[i+2]+=dp[i];
        }
        return dp[n];
    }
};