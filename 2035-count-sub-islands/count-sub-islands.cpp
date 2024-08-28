class Solution {
private:
    vector<pair<int,int>>trav;
public:
    void DFS(int &flag,vector<pair<int,int>>&trav,vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j)
    {
        for(int k = 0 ; k < 4 ; k++ )
        {
           int u = (i+trav[k].first);
           int v = (j+trav[k].second);

           if(u >= 0 && v >= 0 && u < grid2.size() && v < grid2[0].size() && grid2[u][v] == 1)
           {
                if(grid1[u][v] == 1)
                {
                   grid2[u][v] = 0;
                   grid1[u][v] = 0;
                   DFS(flag,trav,grid1,grid2,u,v);
                }
                else
                {
                   flag = 0;
                }
           }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        // Traversing Parameters to be set
        trav.push_back({0,1});
        trav.push_back({1,0});
        trav.push_back({0,-1});
        trav.push_back({-1,0});

        // for each such segment I will check whether this is the complete subset

        int n = grid2.size();
        int m = grid2[0].size();

        int ans = 0;

        for(int i = 0 ; i < n ; i++ )
        {
            for(int j = 0 ; j < m ; j++ )
            {
                if(grid2[i][j] == 1)
                {
                    grid2[i][j] = 0;
                    int flag = 1; // If Flag becomes zero then this is not the sub-island respectively
                    DFS(flag,trav,grid1,grid2,i,j);

                    if(flag == 1 && grid1[i][j] == 1)
                    {
                        cout<<i<<" "<<j<<endl;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};