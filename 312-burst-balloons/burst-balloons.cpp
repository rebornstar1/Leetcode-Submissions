class Solution {
public:
    int cntCoins(vector<int>& nums,int i,int j,vector<vector<int>>&dp)
    {
        // BaseCase Need to be written here
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        int maxi = INT_MIN;
        for(int k = i ; k <= j ; k++ )
        {
            int val = (nums[i-1]*nums[k]*nums[j+1] + cntCoins(nums,k+1,j,dp) + cntCoins(nums,i,k-1,dp));
            maxi = max(maxi,val);
        }
        return dp[i][j] = maxi;
    }

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
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return cntCoins(champ,1,n,dp);
    }
};

// Now Apply DP to this Code