class Solution {
public:
    int cntValue(string &s, string &t, int  i, int j, int champ, vector<vector<int>>&dp)
    {
        if(j == t.size())
        {
            return 1;
        }
        if(i == s.size())
        {
            return 0;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if(s[i] == t[j])
        {
            // Take - Not Take Approach here
            return dp[i][j] = (cntValue(s,t,i+1,j+1,champ,dp)+cntValue(s,t,i+1,j,champ,dp));
        }
        else
        {
            return dp[i][j] = cntValue(s,t,i+1,j,champ,dp);
        }
    }

    int numDistinct(string s, string t) {
        int champ = 0;
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return cntValue(s,t,0,0,champ,dp);
    }
};

// Optimise This Code More