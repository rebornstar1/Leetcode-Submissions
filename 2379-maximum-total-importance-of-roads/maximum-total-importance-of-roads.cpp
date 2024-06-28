class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> adj[n+1];
        for(int i = 0 ; i < roads.size() ; i++ )
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        long long ans = 0, ind = n;
        priority_queue<long long>pq;
        for(int i = 0 ; i < n ; i++ )
        {
            pq.push(adj[i].size());   
        }

        while(!pq.empty())
        {
           long long val = pq.top();
           ans += (ind*val);
           pq.pop();
           ind--;
        }
        return ans;
    }
};

// Maxm Total Importance