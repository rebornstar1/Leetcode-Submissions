class Solution {
public:
    int f(vector<int>&cuts,int i,int j,int cs,int ce,vector<vector<int>> &dp)
    {   
        if(cs > ce)
        {
            return 0;
        }
        if(dp[cs][ce] != -1)
        {
            return dp[cs][ce];
        }
        int mini = INT_MAX;
        for(int k = cs ; k <= ce ; k++ )
        {
            int ans = (f(cuts,i,cuts[k],cs,k-1,dp)+f(cuts,cuts[k],j,k+1,ce,dp)+(j-i));
            mini = min(ans,mini);
        }
        return dp[cs][ce] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int i = 0;
        int j = n;
        int ts = cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(ts+1,vector<int>(ts+1,-1));
        return f(cuts,i,j,0,cuts.size()-1,dp);
    }
};

// Instead of i and j use starting and ending cuts here