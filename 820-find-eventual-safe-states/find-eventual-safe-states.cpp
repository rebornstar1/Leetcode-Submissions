class Solution {
public:
 
    // Now try the same question using DFS DCG Cycle Detection
    bool dfs(vector<vector<int>>& graph, vector<int>&Vis, vector<int> &PathVis, int node)
    {
        Vis[node] = 1;

        for(int i = 0 ; i < graph[node].size() ; i++ )
        {
            if(Vis[graph[node][i]] == 0)
            {
              if(dfs(graph,Vis,PathVis,graph[node][i]))
              {
                Vis[node] = 3;
                return true;
              }
            }
            else if(Vis[graph[node][i]] != 2)
            {
               Vis[node] = 3; 
               return true;
            }
        }
        Vis[node] = 2;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>Vis(V+1,0);
        vector<int>PathVis(V+1,0);
        // 0 => unvisited and 1 => visited
        vector<int>ans;
        for(int i = 0 ; i < V ; i++ )
        {
            if(Vis[i] == 0)
            {
                dfs(graph,Vis,PathVis,i);
            }
        }
        for(int i = 0 ; i < V ; i++ )
        {
            if(Vis[i] == 2)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};