class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // You Need To Create An Adjacnecy List Here
        vector<vector<pair<int,int>>>adj(n+1);

        for(int i = 0 ; i < flights.size() ; i++ )
        {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        // Adjacency List Created Successfully
        vector<int>dist(n+1,INT_MAX);

       // In This Question Number of Stops Matters to me
       queue<vector<int>>qst;
       qst.push({0,src}); // 1 => distance 2 => Index of Node
       dist[src] = 0;
       int a = 0;
       while(!qst.empty() && a <= k)
       {
            int p = qst.size();
            while(p--){
                int val = qst.front()[0];
                int inx = qst.front()[1];
                qst.pop();
                cout<<val<<" "<<inx<<endl;
                
                for(int j = 0 ; j < adj[inx].size() ; j++ )
                {
                    if((dist[adj[inx][j].first]) > (adj[inx][j].second + val))
                    {
                       dist[adj[inx][j].first] =  (adj[inx][j].second + val);
                       qst.push({dist[adj[inx][j].first],adj[inx][j].first});
                    }
                }
            }
            a++;
       }

       if(dist[dst] == INT_MAX) return -1;
       return dist[dst];
    }
};