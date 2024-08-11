class Solution {
public:
    int solve(int amount,int ind,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(amount == 0) return 1;
        if(ind == coins.size() || amount < 0) return 0;

        if(dp[amount][ind] != -1) 
        {
            return dp[amount][ind];
        }
        int jump = amount;

        int ans = 0;
        ans += solve(amount,ind+1,coins,dp);

        while(amount > 0)
        {
            amount -= coins[ind];
            ans += solve(amount,ind+1,coins,dp);
        }
        return dp[jump][ind] = ans;
    }

    int change(int amount, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(5005,vector<int>(305,-1));
        return solve(amount,0,coins,dp);
    }
};

// This isn't the optimized code try for that one