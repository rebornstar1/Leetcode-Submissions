class Solution {
public:
    int findcnt(string &s,int i,int j,vector<vector<int>>&dp)
    {
       if( i >= j ) return 0;

       if(dp[i][j] != -1) return dp[i][j];

       if(s[i] == s[j]) 
       {
          return dp[i][j] = findcnt(s,i+1,j-1,dp);
       }
       else
       {
          return dp[i][j] = (1+min(findcnt(s,i+1,j,dp),findcnt(s,i,j-1,dp)));
       }
    }

    int minInsertions(string s) {
        
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        //  here the string had some starting and ending points
        return findcnt(s,0,n-1,dp);
        // The Approach will be somewhere like Take/Not Take
    }
};

// First Solve it by Top Down Approach but after that solve via the tabulation method