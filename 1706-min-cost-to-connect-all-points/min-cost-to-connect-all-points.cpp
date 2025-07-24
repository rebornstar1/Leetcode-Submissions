class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // basically MST hi banana hai iska

        int n = points.size(); // vertices
        vector<vector<vector<int>>>Adj(n+1);
        for(int i = 0 ; i < n ; i++ )
        {
            for(int j = (i+1) ; j < n ; j++ )
            {
                // find the manhattan distance between these points
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                Adj[i].push_back({j,abs(x1-x2)+abs(y1-y2)});
                Adj[j].push_back({i,abs(x1-x2)+abs(y1-y2)});
            }
        }

        // now we have created the graph use Prim;s Algorithm on this

        vector<int>Visited(n+1,0);

        int ans = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});

        while(!pq.empty())
        {
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(Visited[node] == 1) continue;

            Visited[node] = 1;
            ans += weight;

            for(vector<int> it : Adj[node])
            {
                if(Visited[it[0]] == 0) pq.push({it[1],it[0]});
            }
        }
        return ans;
    }
};

// |xi-xj| + |yi-yj| and so find the |val| itself