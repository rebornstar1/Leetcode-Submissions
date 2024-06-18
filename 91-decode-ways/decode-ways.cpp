class Solution {
public:
    int cntWays(string s,int ind,int val,map<pair<int,int>,int>&dp)
    {
        if(ind == s.size())
        {
            if(val == 0) return 1;
            return 0;
        }
    
        val*=10;
        val += (s[ind]-'0');

        if(dp[{ind,val}] != 0)
        {
            return dp[{ind,val}];
        }

        if(val >= 1 && val <= 26)
        {
            return dp[{ind,val}] = (cntWays(s,ind+1,0,dp)+cntWays(s,ind+1,val,dp));
        }
        else
        {
            return dp[{ind,val}] = 0;
        }
    }

    int numDecodings(string s) {
        int n = s.size();
        map<pair<int,int>,int>dp;
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return cntWays(s,0,0,dp);
    }
};

// First Try to write the recursion correctly