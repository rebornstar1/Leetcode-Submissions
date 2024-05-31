class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Flyod Warshall Algorithm Will be Applicable Here Perfectly
        vector<vector<long long int>>dist(n,vector<long long int>(n,INT_MAX));

        for(int i = 0 ; i < n ; i++ )
        {
            dist[i][i] = 0;
        }

        for(auto it : edges)
        {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        // Now Apply the Floyd Warshall
        for(int i = 0 ; i < n ; i++ )
        {
            for(int j = 0 ; j < n ; j++ )
            {
                for(int k = 0 ; k < n ; k++ )
                {
                    if(dist[j][i] != INT_MAX && dist[i][k] != INT_MAX)
                    {
                    dist[j][k] = min(dist[j][k],dist[j][i]+dist[i][k]);
                    }
                }
            }
        }

        vector<pair<int,int>>vp;
        for(int i = 0 ; i < n ; i++ )
        {
            int cnt = 0;
            for(int j = 0 ; j < n ; j++)
            {
              if(dist[i][j] <= distanceThreshold)
              {
                cnt++;
              }
            }
            vp.push_back({cnt,INT_MAX-i});
        }
        sort(vp.begin(),vp.end());
        return INT_MAX-vp[0].second;
    }
};