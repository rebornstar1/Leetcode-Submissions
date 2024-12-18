class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int N = prices.size();
        for(int i = 0 ; i < N ; i++)
        {
            int discount = 0;
            for(int j = (i+1) ; j  < N ; j++ )
            {
                if(prices[j] <= prices[i])
                {
                    discount = prices[j];
                    break;
                }
            }
            prices[i] -= discount;
        }
        return prices;
    }
};