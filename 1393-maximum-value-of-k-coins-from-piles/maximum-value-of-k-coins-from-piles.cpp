class Solution {
public:
    int func(int index,vector<vector<int>>&piles, int k, vector<vector<int>>&dp)
    {
        if(k <= 0) return 0;
        if(index == piles.size()) return INT_MIN;

        if(dp[index][k] != -1) return dp[index][k];

        // traverse all the possible one's in this itself first
        int ans = INT_MIN;
        int flip = 0;
        for(int i = 0 ; i < piles[index].size() ; i++ )
        {
            flip += piles[index][i];
            if( k >= (i+1)) ans = max(ans,flip+func(index+1,piles,k-i-1,dp));
        }

        return dp[index][k] = max(ans,func(index+1,piles,k,dp));
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return func(0,piles,k,dp);
    }
};

// now we need to optimize this solution correspondingly