class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>temp1(n,0),temp2(n,0);
        temp1[0] = prices[0];
        for(int i = 1 ; i < n ; i++ ) temp1[i] = min(temp1[i-1],prices[i]);

        temp2[n-1] = prices[n-1];
        for(int i = (n-2) ; i >= 0 ; i-- ) temp2[i] = max(temp2[i+1],prices[i]);

        int ans = 0;
        for(int i = 0 ; i < n ; i++ )
        {
        ans = max(ans,abs(temp2[i]-temp1[i]));
        }
        return ans;
    }
};