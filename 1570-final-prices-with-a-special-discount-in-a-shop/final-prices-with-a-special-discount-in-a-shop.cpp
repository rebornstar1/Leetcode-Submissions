class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int N = prices.size();
        vector<int>final_price;
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
            final_price.push_back(prices[i] - discount);
        }
        return final_price;
    }
};