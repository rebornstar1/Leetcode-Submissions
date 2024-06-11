class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,0);
        int ans = 1;
        dp[n-1] = 1;
        for(int i = (n-2) ; i >= 0 ; i-- )
        {
            int flex = 1;
            for(int j = (i+1) ; j < n ; j++ )
            {
                if(nums[j] > nums[i])
                {
                flex = max(flex,1+dp[j]);
                }
            }
            dp[i] = flex;
            ans = max(ans,dp[i]);
        }

        for(int i = 0 ; i < n ; i++ )
        {
            cout<<dp[i]<<" ";
        }
        return ans;
    }
};