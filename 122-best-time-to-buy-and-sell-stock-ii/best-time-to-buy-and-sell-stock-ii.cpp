class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int val = prices[0];
        int n = prices.size();

        int ans = 0;
        for(int i = 1 ; i < n ; i++ )
        {
            if(prices[i] > val)
            {
                ans += (prices[i]-val);
                val = prices[i];
            }
            else
            {
                val = prices[i];
            }
        }
        return ans;
    }
};