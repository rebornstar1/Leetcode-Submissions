class Solution {
private:
    int ans = 0;

public:
    int solve(vector<pair<int,int>>&vp, int m, int n, int a, int b, int ind,vector<vector<vector<int>>>&dp)
    {
        if(ind == vp.size())
        {
            return 0;
        }

        if(dp[ind][a][b] != -1)
        {
            return dp[ind][a][b];
        }

        return dp[ind][a][b] = max(solve(vp,m,n,a,b,ind+1,dp),(m>=(a+vp[ind].first) && n>=(b+vp[ind].second)) ? 1+solve(vp,m,n,a+vp[ind].first,b+vp[ind].second,ind+1,dp) : 0);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>vp;
        vector<vector<vector<int>>>dp(601,vector<vector<int>>(101,vector<int>(101,-1)));
        for(int i = 0 ; i < strs.size() ; i++ )
        {
            int a = 0, b = 0;
            for(int j = 0 ; j < strs[i].size() ; j++ )
            {
                 if(strs[i][j] == '0')
                 {
                   a++; // count of 0's
                 }
                 else
                 {
                   b++; // count of 1's
                 }
            }
            vp.push_back({a,b});
        }

        return solve(vp,m,n,0,0,0,dp);
    }
};