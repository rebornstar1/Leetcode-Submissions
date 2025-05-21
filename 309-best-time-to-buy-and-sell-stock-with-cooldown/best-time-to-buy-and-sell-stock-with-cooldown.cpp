class Solution {
public:
    int evaluate(int index,int isBuy,vector<int>&prices,vector<vector<int>>&dp)
    {
        if(index == prices.size()) return 0;

        if(dp[index][isBuy] != -1) return dp[index][isBuy];

        int a,b;
        if(isBuy == 1)
        {
            // Buyable
           a = (evaluate(index+1,0,prices,dp)-prices[index]);
           b = evaluate(index+1,1,prices,dp);
        }
        else if(isBuy == 0)
        {
            // Sellable
            a = (evaluate(index+1,2,prices,dp)+prices[index]);
            b = evaluate(index+1,0,prices,dp);
        }
        else
        {
            return dp[index][isBuy] = evaluate(index+1,1,prices,dp);
        }

        return dp[index][isBuy] = max(a,b);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return evaluate(0,1,prices,dp);
    }
};

// I guess we can directly go with the approach of the take and not take like