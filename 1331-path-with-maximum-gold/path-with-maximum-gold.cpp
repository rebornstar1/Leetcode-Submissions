class Solution {
public:
    // Write the DFS Code properly which satisfies the single path requirements
    int dfs(vector<vector<int>> &grid,int i,int j){
        // Condition to check whether i and j are in the range
        if((i>=grid.size() || i<0) || (j>=grid[0].size() || j<0)){
            return 0;
        } 
        if(grid[i][j] == 0)
        {
            return 0;
        }
        int val = grid[i][j];
        grid[i][j] = 0;
        int ans = 0;
        //cout<<val<<endl;
        ans = max(ans,dfs(grid,i-1,j));
        ans = max(ans,dfs(grid,i+1,j));
        ans = max(ans,dfs(grid,i,j-1));
        ans = max(ans,dfs(grid,i,j+1));
        grid[i][j] = val;
        return grid[i][j]+ans;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++ )
        {
            for(int j = 0 ; j < m ; j++ )
            {
                if(grid[i][j] > 0)
                {
                  ans = max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};