class Solution {
public:
    // int cntCoins(vector<int>& nums,int i,int j,vector<vector<int>>&dp)
    // {
    //     // BaseCase Need to be written here
    //     if(i > j) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];
        
    //     int maxi = INT_MIN;
    //     for(int k = i ; k <= j ; k++ )
    //     {
    //         int val = (nums[i-1]*nums[k]*nums[j+1] + cntCoins(nums,k+1,j,dp) + cntCoins(nums,i,k-1,dp));
    //         maxi = max(maxi,val);
    //     }
    //     return dp[i][j] = maxi;
    // }

    // Use The Partitions in this code

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int>champ;
        champ.push_back(1);
        for(int i = 0 ; i < n ; i++ )
        {
            champ.push_back(nums[i]);
        }
        champ.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));

        // BaseCase Is Written Here
        for(int i = 0 ; i <= n ; i++ )
        {
            for(int j = 0 ; j <= n ; j++ )
            {
                if(i > j) dp[i][j] = 0;
            }
        }

        for(int i = n ; i > 0 ; i-- )
        {
            for(int j = i ; j <= n ; j++ )
            {
                int maxi = INT_MIN;
                for(int k = j ; k >= i ; k-- )
                {
                   int val = (champ[i-1]*champ[k]*champ[j+1] + dp[i][k-1] + dp[k+1][j]);
                   maxi = max(maxi,val);
                }
                dp[i][j] = maxi;
            }
        }

        return dp[1][n]+1;
    }
};

// Now Write the Tabulation Solution for this