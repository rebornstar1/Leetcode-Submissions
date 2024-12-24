class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // I'm Thinking About an Approach where we can take the maximum possible distances
        // between any two nodes in the graph and based on whether they are even or not we will 
        // take some inference about them even k/2 and odd (k/2)+1 this would represent the 
        // maximum diameter that can be possible Now The Big Question is how I will find the 
        // diameter with the lesser time complexity Maybe It Could About the degree of a particular vertex

        int n = edges1.size(), m = edges2.size();
        int ans = -1, ansS = -1;

        // Need to Create the Adjacency Matrix
        vector<vector<int>>Adj(n+1);
        for(int i = 0 ; i < n ; i++ )
        {
            int u = edges1[i][0];
            int v = edges1[i][1];
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }

        vector<vector<int>>AdjS(m+1);
        for(int i = 0 ; i < m ; i++ )
        {
            int u = edges2[i][0];
            int v = edges2[i][1];
            AdjS[u].push_back(v);
            AdjS[v].push_back(u);
        }
        
        // Challenge 1 
        // Farthest of the Farthest Approach

        vector<int>dist(n+1,INT_MAX);
        vector<int>distS(m+1,INT_MAX);
        dist[0] = 0;
        distS[0] = 0;
        queue<int>qst;
        queue<int>qstS;
        qst.push(0);
        qstS.push(0);

        int level = 0;
        int levelS = 0;

        // Count the Visited Nodes;
        vector<int>Visited(n+1,0);
        vector<int>VisitedS(m+1,0);
        
        while(!qst.empty())
        {
            int N = qst.size();
            while(N--)
            {
                int num = qst.front();
                qst.pop();
                Visited[num] = 1;
                
                dist[num] = min(level,dist[num]);

                for(int i = 0 ; i < Adj[num].size() ; i++ )
                {
                    if(Visited[Adj[num][i]] == 0)
                    {
                        qst.push(Adj[num][i]);
                    }
                }
            }
            level++; // spreading outwards
        }
        
        while(!qstS.empty())
        {
            int N = qstS.size();
            while(N--)
            {
                int num = qstS.front();
                qstS.pop();
                VisitedS[num] = 1;
                
                distS[num] = min(levelS,distS[num]);

                for(int i = 0 ; i < AdjS[num].size() ; i++ )
                {
                    if(VisitedS[AdjS[num][i]] == 0) 
                    {
                        qstS.push(AdjS[num][i]);
                    }
                }
            }
            levelS++; // spreading outwards
        }

        cout<<"distS[i]"<<" ";
        for(int i = 0 ; i < distS.size() ; i++ )
        {
            cout<<distS[i]<<" ";
        }
        cout<<endl;

        // Now Consider the Maximums of them as here for one of the ends level -1 and levelS - 1 respectively
        int ik = -1, ikS = -1;
        for(int i = 0 ; i < dist.size() ; i++ )
        {
            if(dist[i] == (level-1))
            {
                ik = i;
            }
        }
        for(int i = 0 ; i < distS.size() ; i++ )
        {
            if(distS[i] == (levelS-1))
            {
                ikS = i;
            }
        }

        // Now Again Apply the BFS To find out the diameter of the respective Graphs
        
        vector<int>Visited_next(n+1,0);
        vector<int>dist_next(n+1,INT_MAX);
        dist_next[ik] = 0;
        queue<int>qst_next;
        qst_next.push(ik);

        int level_next = 0;

        while(!qst_next.empty())
        {
            int N = qst_next.size();
            while(N--)
            {
                int num = qst_next.front();
                qst_next.pop();
                Visited_next[num] = 1;
                
                dist_next[num] = min(level_next,dist_next[num]);

                for(int i = 0 ; i < Adj[num].size() ; i++ )
                {
                    if(Visited_next[Adj[num][i]] == 0)
                    {
                        qst_next.push(Adj[num][i]);
                    }
                }
            }
            level_next++; // spreading outwards
        }

        for(int i = 0 ; i < dist_next.size() ; i++ )
        {
            ans = max(ans,dist_next[i]);
        }
        cout<<endl;


        vector<int>Visited_nextS(m+1,0);
        vector<int>dist_nextS(m+1,INT_MAX);
        dist_nextS[ikS] = 0;
        queue<int>qst_nextS;
        qst_nextS.push(ikS);

        int level_nextS = 0;

        while(!qst_nextS.empty())
        {
            int N = qst_nextS.size();
            while(N--)
            {
                int num = qst_nextS.front();
                qst_nextS.pop();
                Visited_nextS[num] = 1;
                
                dist_nextS[num] = min(level_nextS,dist_nextS[num]);

                for(int i = 0 ; i < AdjS[num].size() ; i++ )
                {
                    if(Visited_nextS[AdjS[num][i]] == 0)
                    {
                        qst_nextS.push(AdjS[num][i]);
                    }
                }
            }
            level_nextS++; // spreading outwards
        }

        cout<<"dist_nextS[i]"<<" ";
        for(int i = 0 ; i < dist_nextS.size() ; i++ )
        {
            ansS = max(ansS,dist_nextS[i]);
            cout<<dist_nextS[i]<<" ";
        }
        cout<<endl;

        cout<<"ans "<<ans<<" ansS "<<ansS<<endl;
        return max({((ans+1)/2 + (ansS+1)/2) + 1, ans, ansS});
    }
};