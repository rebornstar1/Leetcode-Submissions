class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

       // To Create The Adjacency List
       vector<vector<pair<int,int>>>adj(n+1);
       for(auto it : times)
       {
         adj[it[0]].push_back({it[1],it[2]}); // { Destination, Time Required Here }
       }

        // Simple BFS Approach
        vector<int>dist(n+1,INT_MAX);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});       
        dist[k] = 0; 

        while(!pq.empty())
        {
            int ant = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node])
            {
                if(dist[it.first] > (ant+it.second))
                {
                    dist[it.first] = (ant+it.second);
                    pq.push({dist[it.first],it.first});
                }
            }
        }

        // Applying -1 for INT_MAX Values
        int val = INT_MIN;
        for(int i = 1 ; i <= n ; i++ )
        {
            if(dist[i] == INT_MAX)
            {
                return -1;
            }
            else
            {
               val = max(val,dist[i]);
            }
            cout<<dist[i]<<" ";
        }
        return val;
    }
};