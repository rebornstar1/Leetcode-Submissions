class Solution {
public:
    static bool cmp(int a,int b)
    {
        return a > b; // This is for Decreasing order
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<vector<int>>pq;
        int n = difficulty.size();
        for(int i = 0 ; i < n ; i++ )
        {
            pq.push({profit[i],difficulty[i]});
        }
        sort(worker.begin(),worker.end(),cmp);
        int ans = 0;
        for(int i = 0 ; i < worker.size() ; i++ )
        {
            while(pq.top()[1] > worker[i])
            {
               pq.pop();
               if(pq.empty()) return ans;
            }
            ans += pq.top()[0];
        }
        return ans;
    }
};

// This is O(NlogN) Time Complexity