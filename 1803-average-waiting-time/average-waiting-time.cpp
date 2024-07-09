class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int curr = 0;
        int ind = 0;
        int n = customers.size();
        double ans = 0;
        while(ind != n)
        {
           int u = customers[ind][0];
           int v = customers[ind][1];

           if( u >= curr )
           {
            ans += (v*1.0);
            curr = (u+v);
           }
           else
           {
            ans += ((curr-u+v)*1.0);
            curr += v;
           }
           ind++;
        }
        return ans/n;
    }
};