class Solution {
public:
    void dfs(vector<vector<int>>&grid,vector<vector<int>>&Vis,int i,int j,vector<pair<int,int>>&Trav)
    {
        Vis[i][j] = 1;
        for(int k = 0 ; k < 4 ; k++ )
        {
            int u = (i+Trav[k].first);
            int v = (j+Trav[k].second);
            if(u>=0 && u<grid.size() && v>=0 && v<grid[0].size() && grid[u][v] == 1 && Vis[u][v] == 0)
            {
                dfs(grid,Vis,u,v,Trav);
            }
        }
    }

    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>Vis(n+1,vector<int>(m+1,0));
        // 0 means unvisited and 1 means visited

        // Index Shifting Array
        vector<pair<int,int>>Trav;
        Trav.push_back({0,1});
        Trav.push_back({1,0});
        Trav.push_back({0,-1});
        Trav.push_back({-1,0});

        int cnt = 0;

        for(int i = 0 ; i < n ; i++ )
        {
            for(int j = 0 ; j < m ; j++ )
            {
                if(grid[i][j] == 1 && Vis[i][j] == 0)
                {
                   dfs(grid,Vis,i,j,Trav);
                   cnt++;
                }
            }
        }

        // If there are already disconnected component
        if(cnt > 1 || cnt == 0)
        {
            return 0;
        }

        // First Try the Naive Approach for this problem and then write the optimized one      
        for(int i = 0 ; i < n ; i++ )
        {
            for(int j = 0 ; j < m ; j++ )
            {
                if(grid[i][j] == 0) continue;

                   int flip = 0;
                   grid[i][j] = 0;
                   vector<vector<int>>PathVis(n+1,vector<int>(m+1,0));
                   for(int k = 0 ; k < n ; k++ )
                    {
                        for(int w = 0 ; w < m ; w++ )
                        {
                            if(grid[k][w] == 1 && PathVis[k][w] == 0)
                            {
                              dfs(grid,PathVis,k,w,Trav);
                              flip++;
                            }
                        }
                    }

                grid[i][j] = 1;
                if(flip > 1 || flip == 0) return 1;
            }
        }

        return 2;
    }
};

// Something Related to Articulation Point is there in this question