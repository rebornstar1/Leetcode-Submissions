class Solution {
public:
    void dfST(vector<vector<int>>&adj,int src,stack<int>&qst,vector<int>&Vis)
    {
       Vis[src] = 1;
       for(int i = 0 ; i < adj[src].size() ; i++ )
       {
          if(Vis[adj[src][i]] == 0)
          {
             dfST(adj,adj[src][i],qst,Vis);
          }
       }
       qst.push(src);
    }

    int plaindfs(vector<vector<int>> &adjR,int src,vector<int>&Vis)
    {
        Vis[src] = 1;
        int ans = 0;
        for(int i = 0 ; i < adjR[src].size() ; i++ )
        {
            if(Vis[adjR[src][i]] == 0)
            {
                ans = max(ans,plaindfs(adjR,adjR[src][i],Vis));
            }
        }
        return ans+1;
    }

    int longestCycle(vector<int>& edges) {
        
        // Prepare an Adjacency List

        int n = edges.size();
        vector<vector<int>>adj(n+1);

        for(int i = 0 ; i < n ; i++ )
        {
            if(edges[i] != -1)
            {
               adj[i].push_back(edges[i]);
            }
        }

        // Now Prepare the Timing wise Stack for the Kosaraju's Algorithm
        
        vector<int>Vis(n+1,0);
        stack<int>qst;
        for(int i = 0 ; i < n ; i++ )
        {
            if(Vis[i] == 0)
            {
                dfST(adj,i,qst,Vis);
            }
        }

        // As we had prepared the stack list let's reverse the Adjacency List
        vector<vector<int>>adjR(n+1);
        for(int i = 0 ; i < n ; i++ )
        {
            Vis[i] = 0;
            if(edges[i] != -1)
            {
              adjR[edges[i]].push_back(i);
            }
        }

        int ans = -1;
        while(!qst.empty())
        {
            int num = qst.top();
            qst.pop();
            if(Vis[num] == 0)
            {
               ans = max(ans,plaindfs(adjR,num,Vis));
            }
        }
        if(ans == 1) return -1;
        return ans;
    }
};

// KosaRaju's Algorithm Time Complexity O(V+E);