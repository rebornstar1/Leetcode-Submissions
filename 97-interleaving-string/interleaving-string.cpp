class Solution {
private:
    int n,m,k;
public:
    bool func(string s1,string s2,string s3,int i,int j,int e,vector<vector<vector<int>>>&dp)
    {
        if(e == k)
        {
            if(i == n && j == m) return true;
            return false;
        }

        if(dp[i][j][e] != -1)
        {
            if(dp[i][j][e] == 1) return true;
            return false;
        }

        bool check = false;
        if(i != n && s1[i] == s3[e])
        {
            check |= func(s1,s2,s3,i+1,j,e+1,dp);
        }
        if(j != m && s2[j] == s3[e])
        {
            check |= func(s1,s2,s3,i,j+1,e+1,dp);
        }

        dp[i][j][e] = false;
        if(check) dp[i][j][e] = true;
        return check;
    }

    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size();
        m = s2.size();
        k = s3.size();
       // if(abs(n-m) > 1) return false;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return func(s1,s2,s3,0,0,0,dp);
    }
};

// Now Apply DP on this code

// You Need to write the recursive code for these strings respectively