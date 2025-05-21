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
        vector<vector<int>>dp(n+5,vector<int>(3,-1));
        return evaluate(0,0,fee,prices,dp);
        // isBuy 0 means I can buy
        // isBuy 1 means I can sell
    }
};