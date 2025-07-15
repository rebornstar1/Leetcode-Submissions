class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>>Adj(n+1);
        for(int i = 0 ; i < flights.size() ; i++ )
        {
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];

            Adj[from].push_back({to,price});
        }

        vector<vector<int>>dist(n+1,vector<int>(k+5,INT_MAX));

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,src,k+1});
        dist[src][k+1] = 0;

        int ans = INT_MAX;

        while(!pq.empty())
        {
            int curr_val = pq.top()[0];
            int curr_node = pq.top()[1];
            int rem_flight = pq.top()[2];
            pq.pop();

            if(rem_flight == 0) continue; // we cannot fly further

            for(int i = 0 ; i < Adj[curr_node].size() ; i++ )
            {
                int to = Adj[curr_node][i][0];
                int price = Adj[curr_node][i][1];

                if (curr_val + price < dist[to][rem_flight - 1]) {
                    dist[to][rem_flight - 1] = curr_val + price;
                    pq.push({dist[to][rem_flight - 1], to, rem_flight - 1});
                }
            }
        }

        for(int i = 0 ; i <= k ; i++ ) ans = min(ans,dist[dst][i]);

        return ans == INT_MAX ? -1 : ans;
    }
};

// A 2-D DP way of approach needs to be used here itself