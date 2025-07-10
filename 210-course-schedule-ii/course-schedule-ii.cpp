class Solution {
public:
    bool isCycle(int index, vector<int>&Visited, vector<int>&PathVis, vector<vector<int>>&Adj)
    {
         Visited[index] = 1;
         PathVis[index] = 1;

         bool flex = false;

         for(int i = 0 ; i < Adj[index].size() ; i++ )
         {
            if(PathVis[Adj[index][i]] == 0)
            {
               flex |= isCycle(Adj[index][i],Visited,PathVis,Adj);
            }
            else return true;
         }

         PathVis[index] = 0;
         return flex;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses, u = prerequisites.size();
        
        // check the cycle through the DFS

        // first we need to create the adjacency list for the graph
        vector<int>inDegree(n+1,0);
        vector<vector<int>>Adj(n+1);

        for(int i = 0 ; i < u ; i++ )
        {
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];
            
            Adj[y].push_back(x); // coz this is directed graph itself
            inDegree[x]++;
        }

        // we might need to use the concept of PathVis, so basically after
        // each updation also update the main one

        bool isItCycle = false;

        vector<int>Visited(n+1,0);

        for(int i = 0 ; i < n ; i++ )
        {
            if(Visited[i] == 0)
            {
               vector<int>PathVis(n+1,0);
               isItCycle |= isCycle(i,Visited,PathVis,Adj);
            }
        }

        // now I want to use the toposort in this problem 
        queue<int>qst;
        for(int i = 0 ; i < n ; i++ ) 
        {
            if(inDegree[i] == 0)
            {
               qst.push(i);
            }
        }

        vector<int>ans;

        while(!qst.empty())
        {
            int k = qst.size();
            while(k--)
            {
                int node = qst.front();
                qst.pop();
                ans.push_back(node);

                for(int i = 0 ; i < Adj[node].size() ; i++ )
                {
                    inDegree[Adj[node][i]]--;
                    if(inDegree[Adj[node][i]] == 0) qst.push(Adj[node][i]);
                }
            }
        }
        if(isItCycle) return {};
        return ans;
    }
};

// create the adjacency list first for these prerequisites and 
// check if there is any cycle exist in it, if yes it's impossible else
// use the toposort and the indregree wise bfs