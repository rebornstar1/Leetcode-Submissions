class Solution {
public:
    bool defineMatch(string &s,string &p,int i,int j,vector<vector<int>>&dp)
    {
        if(i == s.size() && j == p.size())
        {
            return true;
        }

        if(i > s.size() || j > p.size())
        {
            return false;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j] == 0 ? false : true ;
        }

        if(p[j] == '*')
        {
           return dp[i][j] = (defineMatch(s,p,i,j+1,dp)|defineMatch(s,p,i+1,j+1,dp)|defineMatch(s,p,i+1,j,dp));
        }
        else if(p[j] == '?')
        {
           return dp[i][j] = (defineMatch(s,p,i+1,j+1,dp));
        }
        else
        {
           if(s[i] != p[j]) return false;
           return dp[i][j] = defineMatch(s,p,i+1,j+1,dp);
        }

        return false;
    }

    bool isMatch(string s, string p) {
        // Apply DP for this code
        // -1 for unvisited 0 for false and 1 for true;
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return defineMatch(s,p,0,0,dp);
    }
};