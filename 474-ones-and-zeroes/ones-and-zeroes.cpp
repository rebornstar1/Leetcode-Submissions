class Solution {
private:
    int ans = 0;
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>vp;
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
        vector<vector<int>>prev(m+1,vector<int>(n+1,0));
        vector<vector<int>>curr(m+1,vector<int>(n+1,0));

        for(int i = 1 ; i <= vp.size() ; i++ )
        {
            for(int j = 0 ; j <= m ; j++ )
            {
                for(int k = 0 ; k <= n ; k++ )
                {
                    curr[j][k] = max(curr[j][k],prev[j][k]);

                    if((j-vp[i-1].first) >= 0 && (k-vp[i-1].second) >= 0)
                    {
                        curr[j][k] = max(curr[j][k],1+prev[j-vp[i-1].first][k-vp[i-1].second]);
                    }

                    ans = max(ans,curr[j][k]);
                }
            }
            prev = curr;
        }
        return ans;
    }
};


// Try Space Optimization in this question