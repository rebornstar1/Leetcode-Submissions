class Solution {
public:
    bool func(int index,int target, vector<int>& nums, vector<vector<int>>&dp)
    {
        if(target < 0) return false;
        if(target == 0) return true;
        if(index == nums.size()) return false;

        if(dp[index][target] != -1) return dp[index][target];

        return dp[index][target] = func(index+1,target-nums[index],nums,dp) | func(index+1,target,nums,dp);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i = 0 ; i < n ; i++ ) sum += nums[i];
        if(sum%2 == 1) return false;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return func(0,sum/2,nums,dp);
    }
};