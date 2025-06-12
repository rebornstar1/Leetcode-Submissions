class Solution {
public:
    int func(int index, int target, vector<int>& nums, vector<vector<int>>&dp)
    {
        if(index == nums.size())
        {
            if(target == 0) return 1;
            return 0;
        }

        if(dp[index][target+2000] != -1) return dp[index][target+2000];

        return dp[index][target+2000] = func(index+1,target+nums[index],nums,dp) + func(index+1,target-nums[index],nums,dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int val = (1000*(n+1));
        vector<vector<int>>dp(n+1,vector<int>(5000,-1));
        return func(0,target,nums,dp);
    }
};

 // 20 * 1000 * 20 