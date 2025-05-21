class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>curr(3,vector<int>(n+5,0));
        vector<vector<int>>prev(3,vector<int>(n+5,0));

        for(int i = 1 ; i <= k ; i++ )
        {
            for(int j = 0 ; j <= 1 ; j++ )
            {
                for(int p = (n-1) ; p >= 0 ; p-- )
                {
                    if(j == 0)
                    {
                       // Sellable
                       curr[0][p] = max(prev[1][p+1]+prices[p],curr[0][p+1]);
                    }
                    else
                    {
                       // Buyable
                       curr[1][p] = max(curr[0][p+1]-prices[p],curr[1][p+1]);
                    }
                }
            }
            prev = curr;
        }

        // I guess we can implement like dp[i] => curr and dp[i-1] => prev

        return curr[1][0];
    }

    // Can you think of any optimal solution for this problem ?
};