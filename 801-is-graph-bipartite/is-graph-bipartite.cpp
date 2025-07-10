class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
       int n = graph.size();
       vector<int>Visited(n+1,-1); 

       // -1 means Not Visited
       // 0 means Visited first
       // 1 means Visited consecutive

       // start with any one of the node let's say it as 0 and do BFS

       int curr = 0;
       queue<int>qst;

       // I haven't handled Disconnected Components

       for(int i = 0 ; i < n ; i++ )
       {
            if(Visited[i] == -1)
            {
                qst.push(i);
                while(!qst.empty())
                {
                    int k = qst.size();
                    while(k--)
                    {
                        int node = qst.front();
                        qst.pop();
                        Visited[node] = curr;

                        for(int i = 0 ; i < graph[node].size() ; i++ )
                        {
                            if(Visited[graph[node][i]] == -1)
                            {
                                qst.push(graph[node][i]);
                            }
                            else if(Visited[graph[node][i]] == curr) return false;
                        }
                    }
                    curr = (curr^1);
                }
            }
       }
       return true;
    }
};

// we want to partition the whole graph in two

// I'll start with the node and a isEven and based on it's values of true
// and false we will decide further things but when we encounter a node 
// first check about true and false rather than is it visited or not and later check about VisitedNess