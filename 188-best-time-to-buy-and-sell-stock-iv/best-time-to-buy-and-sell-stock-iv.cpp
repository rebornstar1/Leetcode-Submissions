class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(k+5,vector<vector<int>>(3,vector<int>(n+5,0)));
        
        for(int i = 1 ; i <= k ; i++ )
        {
            for(int j = 0 ; j <= 1 ; j++ )
            {
                for(int p = (n-1) ; p >= 0 ; p-- )
                {
                    if(j == 0)
                    {
                       // Sellable
                       dp[i][0][p] = max(dp[i-1][1][p+1]+prices[p],dp[i][0][p+1]);
                    }
                    else
                    {
                       // Buyable
                       dp[i][1][p] = max(dp[i][0][p+1]-prices[p],dp[i][1][p+1]);
                    }
                }
            }
        }

        return dp[k][1][0];
    }

    // Can you think of any optimal solution for this problem ?
};