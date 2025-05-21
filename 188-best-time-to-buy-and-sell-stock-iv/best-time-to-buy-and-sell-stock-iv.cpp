class Solution {
public:
    int evaluate(vector<int>& prices,int k,int isBuy,int index,vector<vector<vector<int>>>&dp)
    {
        if(k == 0 || index == prices.size())
        {
            return 0;
        }

        if(dp[k][isBuy][index] != -1) return dp[k][isBuy][index];

        int a,b;

        if(isBuy)
        {
           a = (evaluate(prices,k,0,index+1,dp) - prices[index]);
           b = evaluate(prices,k,1,index+1,dp);
        }
        else
        {
           a = (evaluate(prices,k-1,1,index+1,dp) + prices[index]);
           b = evaluate(prices,k,0,index+1,dp);
        }
        return dp[k][isBuy][index] = max(a,b);
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>>dp(k+5,vector<vector<int>>(3,vector<int>(n+5,-1)));
        return evaluate(prices,k,1,0,dp);
    }

    // 1 means it is buyable 
    // 0 means it is sellable
};