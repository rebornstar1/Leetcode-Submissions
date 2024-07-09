class Solution {
public:
    int UltimateParent(vector<int>&parent,int u)
    {
        if(parent[u] == u) return u;
        return parent[u] = UltimateParent(parent,parent[u]);
    }

    void TakeUnion(vector<int>&parent,vector<int>&size,int u,int v,int &flag)
    {
       int ulp = UltimateParent(parent,u);
       int vlp = UltimateParent(parent,v);

       if(ulp == vlp ) return;

       flag = 1;

       if(size[ulp] > size[vlp])
       {
          parent[vlp] = ulp;
          size[ulp] += size[vlp];
       }
       else
       {
         parent[ulp] = vlp;
         size[vlp] += size[ulp];
       }
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

       vector<int>sizeA(n+1,1);
       vector<int>parentA(n+1,0);
       vector<int>sizeB(n+1,1);
       vector<int>parentB(n+1,0);

       for(int i = 0 ; i <= n ;  i++ ) parentA[i] = i;
       for(int i = 0 ; i <= n ;  i++ ) parentB[i] = i;

       sort(edges.begin(),edges.end());
       int ans = 0;
       for(int i = (edges.size()-1) ; i >= 0 ; i-- )
       {
          int u = edges[i][1];
          int v = edges[i][2];
          if(edges[i][0] == 3)
          {
             int flag = 0;
             TakeUnion(parentA,sizeA,u,v,flag);
             TakeUnion(parentB,sizeB,u,v,flag);
             if(flag != 0) ans++;
          }
          else if(edges[i][0] == 2)
          {
             int flag = 0;
             TakeUnion(parentB,sizeB,u,v,flag);
             if(flag != 0) ans++;
          }
          else
          {
              int flag = 0;
             TakeUnion(parentA,sizeA,u,v,flag);
             if(flag != 0) ans++;
          }
       }

       int cnt = 0;
       for(int i = 1 ; i <= n ; i++ )
       {
          if(sizeA[i] == n) cnt++;
          if(sizeB[i] == n) cnt++;
       }
       if(cnt != 2) return -1;

       return edges.size()-ans;
    }
};










// This is the Bridge way trying for this code

// class Solution {
// public:
//     void dfs(vector<vector<int>>&Alice,vector<int>&timeA,vector<int>&minAdjA,int src)
//     {
//           for(auto it : Alice[src])
//           {
//                 if(timeA[it] != -1)
//                 {
//                    timeA[it] = (timeA[src]);
//                    minAdjA[it] = (minAdjA[src]);
//                    dfs(Alice,timeA,minAdjA,it);
//                 }
//                 else
//                 {
//                     minAdjA[src] = min(minAdjA[src],minAdjA[it]); 
//                 }
//           }
//     }


//     int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
//         vector<int> timeA(n+1,-1),minAdjA(n+1,-1),timeB(n+1,-1),minAdjB(n+1,-1);

//         // Prepare Adjacency List
//         vector<vector<int>>Alice(n+1);
//         vector<vector<int>>Bob(n+1);
//         for(int i = 0 ; i < edges.size() ; i++ )
//         {
//             int type = edges[i][0];
//             int u = edges[i][1];
//             int v = edges[i][2];

//             if((type == 1) || (type == 3))
//             {
//                 Alice[u].push_back(v);
//                 Alice[v].push_back(u);
//             }

//             if((type == 2) || (type == 3))
//             {
//                 Bob[u].push_back(v);
//                 Bob[v].push_back(u);
//             }
//         }

//         timeA[0] = 0;
//         minAdjA[0] = 0;
//         dfs(Alice,timeA,minAdjA,0);
//         timeA[0] = 0;
//         minAdjA[0] = 0;
//         dfs(Alice,timeA,minAdjA,0);
//         return 0;
//     }
// };