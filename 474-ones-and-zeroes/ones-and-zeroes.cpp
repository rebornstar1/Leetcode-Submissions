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
        vector<vector<vector<int>>>dp(601,vector<vector<int>>(101,vector<int>(101,0)));
        int N = strs.size();

        // Counting of 1's and 0's
        for(int i = 0 ; i < strs.size() ; i++ )
        {
            int x = 0, y = 0;
            for(int j = 0 ; j < strs[i].size() ; j++ )
            {
                if(strs[i][j] == '0')
                {
                    x++;
                }
                else
                {
                    y++;
                }
            }
            vp.push_back({x,y});
        }
        
        // Tabulation Solution for this Approach
        dp[0][0][0] = 0;

        for(int i = 1 ; i <= vp.size() ; i++ )
        {
            for(int j = 0 ; j <= m ; j++ )
            {
                for(int k = 0 ; k <= n ; k++ )
                {
                    dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]);

                    if((j-vp[i-1].first) >= 0 && (k-vp[i-1].second) >= 0)
                    {
                        dp[i][j][k] = max(dp[i][j][k],1+dp[i-1][j-vp[i-1].first][k-vp[i-1].second]);
                    }

                    ans = max(ans,dp[i][j][k]);
                }
            }
        }

        return ans;
    }
};


// Write The Tabulation Approach for this