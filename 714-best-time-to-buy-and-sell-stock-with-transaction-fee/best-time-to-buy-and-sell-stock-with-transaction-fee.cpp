class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int>prev(3,0);
        vector<int>curr(3,0);

        for(int i = (n-1) ; i >= 0 ; i-- )
        {
            for(int j = 0 ; j <= 1 ; j++ )
            {
                if(j == 0)
                {
                    curr[0] = max(prev[0],prev[1]-prices[i]);
                }
                else
                {
                    curr[1] = max(prev[1],prev[0]+prices[i]-fee);  
                }
            }
            prev = curr;
        }
        return prev[0];
    }
};

// See If you can reduce the space complexity of this problem

// First Converting this solution to iterative approach