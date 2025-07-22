class Solution {
public:
    int func(int index,vector<int>&stones, int target, vector<vector<int>>&dp)
    {
        if(target < 0) return INT_MAX;
        if(index == stones.size()) return target;

        if(dp[index][target] != -1) return dp[index][target];

        return dp[index][target] = min(func(index+1,stones,target-stones[index],dp),func(index+1,stones,target,dp));
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int i = 0 ; i < n ; i++ ) sum += stones[i];

        int target = sum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int achievableTarget = (target-func(0,stones,target,dp));
        return (sum -= 2*achievableTarget);
    }
};

// add up this in a way like the end value only should be lesser than the weight itself


