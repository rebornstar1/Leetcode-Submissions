class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i = 0 ; i < n ; i++ ) sum += nums[i];
        if(sum%2 == 1) return false;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));

        for(int i = 0 ; i <= n ; i++ ) dp[i][0] = 1;

        for(int i = (n-1) ; i >= 0 ; i-- )
        {
            for(int j = 0 ; j <= (sum/2) ; j++ )
            {
                int val1 = ((j-nums[i]) >= 0 ? dp[i+1][j-nums[i]] : 0);
                int val2 = dp[i+1][j];
                dp[i][j] = (val1 | val2); 
            }
        }
        return dp[0][sum/2];
    }
};

// Space Optimization could be possible