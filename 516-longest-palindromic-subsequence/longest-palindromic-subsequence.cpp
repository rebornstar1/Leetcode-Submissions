class Solution {
public:
    int cntlongest(string &s,int i,int j,vector<vector<int>>&dp)
    {
        if(i > j) return 0;
        if(i == j) return 1;

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if(s[i] == s[j])
        {
          return dp[i][j] = (2+cntlongest(s,i+1,j-1,dp)); 
        }
        else
        {
          return dp[i][j] = max(cntlongest(s,i+1,j,dp),cntlongest(s,i,j-1,dp));
        }
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return cntlongest(s,0,n-1,dp);
    }
};

// Now Optimise This Code Using DP