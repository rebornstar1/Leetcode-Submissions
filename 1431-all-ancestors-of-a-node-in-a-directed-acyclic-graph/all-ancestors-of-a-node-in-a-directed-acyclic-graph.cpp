class Solution {
public:
    void FindAncestors(vector<vector<int>> &ans,int src,vector<vector<int>> &adj,int ances,vector<int>&prev)
    {
        for(int i = 0 ; i < adj[src].size() ; i++ )
        {
            if(prev[adj[src][i]] == -1)
            {
               ans[adj[src][i]].push_back(ances);
               prev[adj[src][i]] = 1;
               FindAncestors(ans,adj[src][i],adj,ances,prev);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        // Prepare An Adjacency List
        vector<vector<int>>adj(n);
        for(int i = 0 ; i < edges.size() ; i++ )
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        vector<vector<int>> ans(n);
        for(int i = 0 ; i < n ; i++ )
        {
           vector<int>prev(n+1,-1);
           FindAncestors(ans,i,adj,i,prev);
        }
        return ans;
    }
};