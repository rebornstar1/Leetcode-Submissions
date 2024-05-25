class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // first of all create the Adjacency List for this grid
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        int m = grid[0].size();

        // Let's Just Try This Question Without Using Adjacency List

        // vector<pair<int,int>> adj[n+1][m+1];
        // for(int i = 0 ; i < n ; i++ )
        // {
        //     for(int j = 0 ; j < n ; j ++ )
        //     {
        //         if(grid[i][j] == 0)
        //         {
        //             // Now It's Adjacent which are also 0
        //             for(int k = -1 ; k <= 1 ; k++ )
        //             {
        //                 for(int p = -1 ; p <= 1 ; p++ )
        //                 {
        //                     if(k == 0 && p == 0) continue;
        //                     int u = i+k;
        //                     int v = j+p;
        //                     if(u >= 0 && u < n && v >= 0 && v < m && grid[u][v] == 0)
        //                     {
        //                       adj[i][j].push_back({u,v});
        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }
        // Adjacency List Is Created

        // I Will Apply Breadth First Search Here
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<int>temp;
        temp.push_back(1);
        temp.push_back(0);
        temp.push_back(0);
        pq.push(temp);

        // A distance 2-D Vector Needs To Be Created
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 1;

        while(!pq.empty())
        {
            int wet = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();

            for(int k = -1 ; k <= 1 ; k++ )
            {
                for(int f = -1 ; f <= 1 ; f++ )
                {
                    if(k == 0 && f == 0 ) continue;
                    int u = i+k;
                    int v = j+f;
                    if(u >= 0 && u < n && v >= 0 && v < m && grid[u][v] == 0)
                    {
                        if((wet+1) < dist[u][v])
                        {
                            dist[u][v] = (wet+1);
                            vector<int>gpa;
                            gpa.push_back(dist[u][v]);
                            gpa.push_back(u);
                            gpa.push_back(v);
                            pq.push(gpa);
                        }
                    }
                }
            }
        }

        for(int i = 0 ; i < n ; i++ )
        {
            for(int j = 0 ; j < n ; j++ )
            {
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }

        if(dist[n-1][m-1] == INT_MAX) return -1;
        return dist[n-1][m-1];
    }
};

// Optimize This Code Now