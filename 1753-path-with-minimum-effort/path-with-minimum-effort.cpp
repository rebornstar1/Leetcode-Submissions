class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        // Initially all the efforts are set to zero
        vector<vector<int>>tp(n,vector<int>(m,INT_MAX));
        tp[0][0] = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>qst;
        // Using Priority Queue The Unnecessary Caluclations were removed
        qst.push({0,0,0});

        vector<pair<int,int>>flex;
        flex.push_back({0,1});
        flex.push_back({1,0});
        flex.push_back({0,-1});
        flex.push_back({-1,0});

        while(!qst.empty())
        {
           int eff = qst.top()[0];
           int i = qst.top()[1];
           int j = qst.top()[2];
           if(i == (n-1) && j == (m-1)) return tp[n-1][m-1];
           qst.pop();

           for(int k = 0 ; k < flex.size() ; k++ )
           {
                int u = i+flex[k].first;
                int v = j+flex[k].second;
                if(u >= 0 && u < n && v >= 0 && v < m)
                {
                    if(max(eff,abs(heights[i][j]-heights[u][v])) < tp[u][v])
                    {
                        tp[u][v] = max(eff,abs(heights[i][j]-heights[u][v]));
                        qst.push({tp[u][v],u,v});
                    }
                }
           }
        }
        return tp[n-1][m-1];
    }
};

// Optimize it more