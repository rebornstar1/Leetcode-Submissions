class Solution {
public:
    int func(int index,int k,vector<vector<int>>& events, vector<vector<int>>&dp)
    {
        int n = events.size();
        if(index == n || k == 0) return 0;


        if(dp[index][k] != -1) return dp[index][k];

        int val1 = func(index+1,k,events,dp);

        // do binary search over 
        int endDay = events[index][1];
        int low = index + 1, high = events.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (events[mid][0] > endDay)
                high = mid;
            else
                low = mid + 1;
        }
        // Now, `low` is the first index where startDay > endDay
        int val2 = events[index][2];
        if (low < events.size()) {
            val2 += func(low, k - 1, events, dp);
        }
        dp[index][k] = max(val1, val2);
        return dp[index][k];

    }

    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size(); // number of events

        // take not take + binary search

        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));

        sort(events.begin(),events.end()); // this is done for applying the binary search
        return func(0,k,events,dp);
    }
};

// try to first write the recursive solution for this question