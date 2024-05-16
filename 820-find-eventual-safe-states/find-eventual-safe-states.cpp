class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>>incoming(V+1);
        for(int i = 0 ; i < V ; i++)
        {
            for(int j = 0 ; j < graph[i].size() ; j++)
            {
                incoming[graph[i][j]].push_back(i);
            }
        }
        vector<int>outDegree(V+1,0);
        for(int i = 0 ; i < V ; i++ )
        {
            outDegree[i]+=graph[i].size(); // OutDegree's for every position are evaluated
        }
        queue<int>qst;
        for(int i = 0 ; i < V ; i++ )
        {
            if(outDegree[i] == 0)
            {
                qst.push(i);
            }
        }
        vector<int>ans;
        while(!qst.empty())
        {
           int val = qst.front();
           qst.pop();
           ans.push_back(val);
           for(int i = 0 ; i < incoming[val].size() ; i++ )
           {
             outDegree[incoming[val][i]]--;
             if(outDegree[incoming[val][i]] == 0) qst.push(incoming[val][i]);
           }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};