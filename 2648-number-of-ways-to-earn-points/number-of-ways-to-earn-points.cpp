class Solution {
public:
    int func(int index,int target,vector<vector<int>>& types, vector<vector<int>>&dp)
    {
        // we need to set some base case here
        if(index == types.size() || target < 0) 
        {
            if(target == 0) return 1;
            return 0;
        }

        if(dp[index][target] != -1) return dp[index][target]%1000000007;

        int ans = 0;
        for(int i = 0 ; i <= types[index][0] ; i++ )
        {
            ans = (ans+func(index+1,target-(i*types[index][1]),types,dp))%1000000007; 
        }
        return dp[index][target] = ans%1000000007;
    }

    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return func(0,target,types,dp);
    }
};

// Now we need to apply the Optimization on this problem

// This a kind of unbounded knapsack problem present here