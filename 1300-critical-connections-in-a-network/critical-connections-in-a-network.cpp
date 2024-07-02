class Solution {
private:
  int timer = 1;
  void dfs(int node,int parent,vector<vector<int>> &adj, vector<int> &vis,int time[],int low[],vector<vector<int>> &bridges)
  {
       vis[node] = 1;
       time[node] = timer;
       low[node] = timer;
       timer++;

       for(int i = 0 ; i < adj[node].size() ; i++ )
       {
          if(adj[node][i] == parent) continue;
          if(vis[adj[node][i]] == 0)
          {
             dfs(adj[node][i],node,adj,vis,time,low,bridges);
             low[node] = min(low[node],low[adj[node][i]]);
             if(low[adj[node][i]] > time[node])
             {
                bridges.push_back({adj[node][i],node});
             }
          }
          else
          {
            low[node] = min(low[node],low[adj[node][i]]);
          }
       }
  }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        // Prepare an Adajcency List
        vector<vector<int>>adj(n+1);
        for(int i = 0 ; i < connections.size() ; i++ )
        {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>vis(n+1,0);
        int time[n+1]; // DFS Time of Insertion
        int low[n+1]; // Minm Lowest Time Insertion of all Adjacent Nodes

        vector<vector<int>>bridges;
        dfs(0,-1,adj,vis,time,low,bridges);

        for(int i = 0 ; i < n ; i++ ) cout<<time[i]<<" ";
        cout<<endl;
        for(int i = 0 ; i < n ; i++ ) cout<<low[i]<<" ";
        cout<<endl;
        return bridges;
    }
};

// Solve This Using the Tarjan's Algorithm