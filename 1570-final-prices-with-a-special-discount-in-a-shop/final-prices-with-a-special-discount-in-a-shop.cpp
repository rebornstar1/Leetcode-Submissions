class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // int N = prices.size();
        // for(int i = 0 ; i < N ; i++)
        // {
        //     int discount = 0;
        //     for(int j = (i+1) ; j  < N ; j++ )
        //     {
        //         if(prices[j] <= prices[i])
        //         {
        //             discount = prices[j];
        //             break;
        //         }
        //     }
        //     prices[i] -= discount;
        // }
        // return prices;

        // The More better solution in terms of time complexity would be using stack here

        int N = prices.size();
        stack<pair<int,int>>st;
        for(int i = 0 ; i < N ; i++ )
        {
            if(st.empty())
            {
                st.push({prices[i],i});
            }
            else if(st.top().first >= prices[i])
            {
                while(!st.empty() && st.top().first >= prices[i]){
                    prices[st.top().second] -= prices[i];
                    st.pop();
                }
                st.push({prices[i],i});
            }
            else
            {
                st.push({prices[i],i});
            }
        }
        return prices;
    }
};