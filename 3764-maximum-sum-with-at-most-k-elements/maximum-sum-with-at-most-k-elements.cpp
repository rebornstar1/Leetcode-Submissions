class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<pair<int,int>>pq;
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0 ; i < n ; i++ )
        {
            for(int j = 0 ; j < m ; j++ )
            {
                pq.push({grid[i][j],i});
            }
        }

        long long ans = 0;
        while(!pq.empty() && k)
        {
            int num1 = pq.top().first;
            int num2 = pq.top().second;
            pq.pop();

            if(limits[num2] > 0)
            {
                ans += num1;
                k--;
                limits[num2]--;
            }
        }
        return ans;
    }
};