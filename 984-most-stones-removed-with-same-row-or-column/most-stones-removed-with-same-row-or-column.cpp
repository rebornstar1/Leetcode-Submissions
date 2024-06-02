class Solution {
public:
    int findUpar(vector<int>&parent,int tp)
    {
         if(tp == parent[tp]) return tp;
         return parent[tp] = findUpar(parent,parent[tp]);
    }

    void fUnion(vector<int>&parent, vector<int>&size, int x , int  y)
    {
        int px = findUpar(parent,x);
        int py = findUpar(parent,y);
        if(px == py) return;

        if(size[px] < size[py])
        {
           parent[px] = py;
           size[py] += size[px];
        }
        else
        {
           parent[py] = px;
           size[px] += size[py];
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        // I may need to create an Adjacency List For This First

        int V = stones.size(); // The Total Number of Vertices

        vector<int>parent(V+1,0);
        vector<int>size(V+1,1);
        for(int i = 0 ; i <= V ; i++ )
        {
            parent[i] = i; // Same Assinged Accordingly
        }

        vector<vector<int>>adj(V+1);
        for(int i = 0 ; i < stones.size() ; i++ )
        {
            int cnt = 0;
            for(int j = 0 ; j < stones.size() ; j++ )
            {
                if(i!=j)
                {
                    // If we aren't comparing it with himself
                    if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    {
                        fUnion(parent,size,i+1,j+1);
                    }
                }
            }
        }

        // Created The Adjacency List Successfully

        // for(int i = 1 ; i <= V ; i++ )
        // {
        //     for(int j = 0 ; j < adj[i].size() ; j++ )
        //     {
        //        fUnion(parent,size,i,adj[i][j]);
        //     }
        // }

        int cnt = 0;
        for(int i = 1 ; i <= V ; i++ )
        {
            if(i == parent[i])
            {
                cnt++;
            }
        }

        return stones.size()-cnt;      
    }
};

//  Check Whether We can optimse this code more ?
