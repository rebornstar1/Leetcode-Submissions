class Solution {
public:
    bool solve(string &A,string &B,int i,int j,vector<vector<int>>&dp)
    {
        // Base Case
        if(i == A.size() && j == B.size())
        {
            return true;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        bool ans = false;
        if(i!=A.size() && j!=B.size() && A[i] == B[j])
        {
            ans |= solve(A,B,i+1,j+1,dp);
        }
        else if(B[j] == '?')
        {
            if(i == A.size())
            {
                return false;
            }
            else
            {
            ans |= solve(A,B,i+1,j+1,dp);
            }
        }
        else if(B[j] == '*')
        {
            if(i == A.size())
            {
                ans |= solve(A,B,i,j+1,dp);
            }
            else
            {
                ans |= (solve(A,B,i,j+1,dp)|solve(A,B,i+1,j+1,dp)|solve(A,B,i+1,j,dp));   
            }
        }
        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+5,vector<int>(m+5,-1));
        return solve(s,p,0,0,dp);
    }
};

// Try for it's Tabulation Solution