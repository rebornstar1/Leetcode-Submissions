class Solution {
public:
    void processTree(int startNode, vector<vector<int>>&AdjMatrix, bool evenHai, unordered_map<int,int>&mp, int &countOf)
    {
         queue<int>qst;
         qst.push(startNode);
         int n = AdjMatrix.size();
         vector<int>Visited(n+1,0);
         int level = 0;
         if(evenHai) mp[startNode]++;
         if(evenHai) countOf++;
        
         while(!qst.empty())
         {
            int p = qst.size();
            while(p--)
            {
                int node = qst.front();
                qst.pop();
                Visited[node]++;
                
                for(int i = 0 ; i < AdjMatrix[node].size() ; i++ )
                {
                    if(Visited[AdjMatrix[node][i]] == 0)
                    {
                        qst.push(AdjMatrix[node][i]);
                        if(level %2 == 1 && evenHai)
                        {
                            countOf++;
                            mp[AdjMatrix[node][i]]++;
                        }
                        else if(level % 2 == 0 && !evenHai)
                        {
                            countOf++;
                            mp[AdjMatrix[node][i]]++;
                        }
                    }
                }
            }
            level++;
         }
    }
    
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // Create the Adjacency Matrix for both the Graphs
        int n = edges1.size(); // Total (n+1) nodes in graph1
        int m = edges2.size(); // Total (m+1) nodes in graph2
        
        vector<vector<int>>AdjOne(n+1);
        vector<vector<int>>AdjTwo(m+1);
        
        for(int i = 0 ; i < n ; i++ )
        {
            int u = edges1[i][0];
            int v = edges1[i][1];
            AdjOne[u].push_back(v);
            AdjOne[v].push_back(u);
        }
        
        for(int i = 0 ; i < m ; i++ )
        {
            int u = edges2[i][0];
            int v = edges2[i][1];
            AdjTwo[u].push_back(v);
            AdjTwo[v].push_back(u);
        }
        
        // Better Create a Funtion for this instead
        unordered_map<int,int>evenFirst, oddFirst, evenSecond, oddSecond;
        int countEvenFirst = 0, countOddFirst = 0, countEvenSecond = 0, countOddSecond = 0;
        processTree(edges1[0][0],AdjOne,true,evenFirst,countEvenFirst);
        processTree(edges1[0][1],AdjOne,true,oddFirst,countOddFirst);
        processTree(edges2[0][0],AdjTwo,false,evenSecond,countEvenSecond); // 0 and 1 respectively
        processTree(edges2[0][1],AdjTwo,false,oddSecond,countOddSecond);
        
//         cout<<countEvenFirst<<endl;
//         for(auto it : evenFirst)
//         {
//             cout<<it.first<<" "<<it.second<<"  ";
//         }
//         cout<<endl;
        
//         cout<<countOddFirst<<endl;
//         for(auto it : oddFirst)
//         {
//             cout<<it.first<<" "<<it.second<<"  ";
//         }
//         cout<<endl;
        
//         cout<<countEvenSecond<<endl;
//         for(auto it : evenSecond)
//         {
//             cout<<it.first<<" "<<it.second<<"  ";
//         }
//         cout<<endl;
        
//         cout<<countOddSecond<<endl;
//         for(auto it : oddSecond)
//         {
//             cout<<it.first<<" "<<it.second<<"  ";
//         }
        
        int tempVal = evenSecond.size();
        int flexyup = oddSecond.size();
        tempVal = max(tempVal,flexyup);
        vector<int>ans;
        

        for(int i = 0 ; i <= n ; i++ )
        {
            if(evenFirst[i] != 0)
            {
                ans.push_back(countEvenFirst + tempVal);
            }
            else
            {
                ans.push_back(countOddFirst + tempVal);
            }
            
        }
        
        return ans;
    }
};