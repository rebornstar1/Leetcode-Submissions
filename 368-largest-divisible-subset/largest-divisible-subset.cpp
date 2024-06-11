class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>dp(n+1,1);
        
        int val = 1;
        for(int i = (n-2) ; i >= 0 ; i-- )
        {
            for(int j = (i+1) ; j < n ; j++ )
            {
                if(nums[j]%nums[i]==0 || nums[i]%nums[j]==0)
                {
                    dp[i] = max(dp[j]+1,dp[i]);
                }
            }
            val = max(val,dp[i]);
        }

        for(int i = 0 ; i < n ; i++ )
        {
            cout<<dp[i]<<" ";
        }

        vector<int>ans;
        int jump = 0;
        for(int i = 0 ; i < n ; i++ )
        {
            int ff = ans.size();
            int test = 0;
            if(ff != 0) test = ans[ff-1];
            if(dp[i] == val && (test % nums[i] == 0 || nums[i] % test == 0))
            {
                ans.push_back(nums[i]);
                val--;
                jump = i;
            }
        }
        return ans;
    }
};

// First Try the LCS First O(N^2) Solution