class Solution {
public:
    int cntMaxSum(vector<int>& arr,int k,int ind,vector<int>&dp)
    {
        if(ind == arr.size()) return 0;

        if(dp[ind] != -1) return dp[ind];

        int maxi = INT_MIN;
        int ansi = INT_MIN;
        int flex = arr.size();
        for(int j = ind ; j < min(flex,ind+k) ; j++ )
        {
           maxi = max(maxi,arr[j]);
           ansi = max(ansi,maxi*(j-ind+1) + cntMaxSum(arr,k,j+1,dp));
        }
        return dp[ind] = ansi;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,-1);
        return cntMaxSum(arr,k,0,dp);
    }
};

// Write the Simple Recursion for this