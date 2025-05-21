class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>curr(2,vector<int>(n+1,0));
        vector<vector<int>>prev(2,vector<int>(n+1,0));

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

        // Think of If you can further optimise this solution, even after the space optimization
        return curr[1][0];
    }

    // Can you think of any optimal solution for this problem ?
};