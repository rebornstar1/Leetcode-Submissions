class Solution {
public:
    int evaluate(int index,int isBuy,int fee,vector<int>& prices,vector<vector<int>>&dp)
    {
        if(index == prices.size()) return 0;

        if(dp[index][isBuy] != -1) return dp[index][isBuy];

        int a,b;
        if(isBuy)
        {
            // Sellable
            a = evaluate(index+1,1,fee,prices,dp);
            b = (evaluate(index+1,0,fee,prices,dp)+prices[index]-fee);
        }
        else
        {
            // Buyable
            a = evaluate(index+1,0,fee,prices,dp);
            b = evaluate(index+1,1,fee,prices,dp)-prices[index];
        }
        return dp[index][isBuy] = max(a,b);
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+5,vector<int>(3,0));


        for(int i = (n-1) ; i >= 0 ; i-- )
        {
            for(int j = 0 ; j <= 1 ; j++ )
            {
                if(j == 0)
                {
                    dp[i][0] = max(dp[i+1][0],dp[i+1][1]-prices[i]);
                }
                else
                {
                    dp[i][1] = max(dp[i+1][1],dp[i+1][0]+prices[i]-fee);  
                }
            }
        }

        return dp[0][0];
    }
};

// First Converting this solution to iterative approach