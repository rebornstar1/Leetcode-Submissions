class Solution {
public:
    int UltParent(vector<int>&parent,int x)
    {
        if(x == parent[x]) return x;
        return parent[x] = UltParent(parent,parent[x]);
    }

    void TakeUnion(vector<int>&parent,vector<int>&size,int x,int y)
    {
        int px = UltParent(parent,x);
        int py = UltParent(parent,y);

        if(px == py) return;

        if(size[px] > size[py])
        {
           parent[py] = px;
           size[px] += size[py];
        } 
        else
        {
           parent[px] = py;
           size[py] += size[px];
        }
    }

    // To Avoid the Confusion Just Take it as 0 - referenced for size and parent too

    int largestIsland(vector<vector<int>>& grid) {
        // for every node possible the number is ((row no-1)*row size)+(column no + 1 )

        int n = grid.size(); // column Size
        int m = grid[0].size(); // Row Size

        // Every Node in the form of (m*(R-1))+(C+1);

        vector<int>parent(n*m+2);
        vector<int>size(n*m+2,1);
        for(int i = 0 ; i < parent.size() ; i++ )
        {
            parent[i] = i;
        }

        // To Address the Adjacents Here
        vector<pair<int,int>>adj;
        adj.push_back({0,1});
        adj.push_back({1,0});
        adj.push_back({0,-1});
        adj.push_back({-1,0});

        for(int i = 0 ; i < n ; i++ )
        {
            for(int j = 0 ; j < m ; j++ )
            {
                // Initially All the Sizes Were Zero,
                if(grid[i][j] == 1)
                {
                    for(int k = 0 ; k < 4 ; k++ )
                    {
                        int u = (i + adj[k].first);
                        int v = (j + adj[k].second);
                        if( u >= 0 && u < n && v >= 0 && v < m && grid[u][v] == 1)
                        {
                            TakeUnion(parent,size,i*m+j,u*m+v);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0 ; i < n ; i++ )
        {
            for(int j = 0 ; j < m ; j++ )
            {
                if(grid[i][j] == 0)
                {
                    int cnt = 0;
                    set<int>check;
                    for(int k = 0 ; k < 4 ; k++ )
                    {
                        int u = (i + adj[k].first);
                        int v = (j + adj[k].second);
                        if( u >= 0 && u < n && v >= 0 && v < m && grid[u][v] == 1)
                        {
                            int cpp = UltParent(parent,u*m+v);
                            if(check.find(cpp) != check.end()) continue;
                            cnt += size[cpp];
                            check.insert(cpp);
                        }
                    }
                    ans = max(ans,cnt+1);
                }
                else
                {
                    ans = max(ans,size[i*m+j]);
                }
            }
        }

        return ans;
    }
};

// Time Limit Exceeded for the Code