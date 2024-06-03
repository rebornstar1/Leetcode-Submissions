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

    int swimInWater(vector<vector<int>>& grid) {
        // Target Is Count the time in which the Ultimate Parent of (0,0) & (n-1,n-1)
        // becomes the same

        // Adjacent Elements
        vector<pair<int,int>>adj;
        adj.push_back({0,1});
        adj.push_back({1,0});
        adj.push_back({0,-1});
        adj.push_back({-1,0});


        int n = grid.size();

        vector<int>parent(n*n+1,0);
        for(int i = 0 ; i <= n*n ; i++ ) parent[i] = i;
        vector<int>size(n*n+1,1);

        for(int i = 0 ; i <= (n*n) ; i++ )
        {
            for(int j = 0 ; j < n ; j++ )
            {
                for(int p = 0 ; p < n ; p++ )
                {
                   for(int k = 0 ; k < 4 ; k++ )
                    {
                        int u = (j + adj[k].first);
                        int v = (p + adj[k].second);
                        if( u >= 0 && u < n && v >= 0 && v < n && grid[u][v]<=i && grid[j][p]<=i)
                        {
                            TakeUnion(parent,size,j*n+p,u*n+v);
                        }
                    }
                }
            }
            if(UltParent(parent,0) == UltParent(parent,n*n-1)) return i;
        }

        return -1;
    }
};

// RunTime Is Extremely High, You Need to Optimise This Code Now