class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<unsigned int>dp(amount+1,0);
        dp[0] = 1;
        
        for(int i = 0 ; i < n ; i++ )
        {
            for(int j = 0 ; j <= amount ; j++ )
            {
                if(dp[j] > 0 && ((j+coins[i]) <= amount))
                {
                    dp[j+coins[i]] += dp[j];
                }
            }
        }

        return dp[amount];
    }
};

// we want the combinations for this