class Solution {
public:
    static bool cmpvec(vector<int> a,vector<int> b)
    {
        return a > b; // This is for Decreasing order
    }

    static bool cmp(int a,int b)
    {
        return a > b;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<vector<int>>pq;
        int n = difficulty.size();
        for(int i = 0 ; i < n ; i++ )
        {
            pq.push_back({profit[i],difficulty[i]});
        }
        sort(pq.begin(),pq.end(),cmpvec);
        sort(worker.begin(),worker.end(),cmp);
        int ans = 0;
        int ind = 0;
        for(int i = 0 ; i < worker.size() ; i++ )
        {
               while(pq[ind][1] > worker[i])
               {
                 ind++;
                 if(ind == n) return ans;
               }

             ans += pq[ind][0];
        }
        return ans;
    }
};

// This is O(NlogN) Time Complexity