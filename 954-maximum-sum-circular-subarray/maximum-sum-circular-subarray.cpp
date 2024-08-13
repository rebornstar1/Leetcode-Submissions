class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int flag = 0;
        int sum = 0;

        // Now Apply Kadane's Algorithm Here
        int curr = 0, maxi = nums[0];
        for(int i = 0 ; i < n ; i++ )
        {
            curr += nums[i];
            maxi = max(curr,maxi);
            if(curr < 0 ) curr = 0;
            sum += nums[i];
            if(nums[i] >= 0) flag = 1;
        }

        // Now find the Minimum SubArray sum
        int flex = 0, jump = nums[0];
        for(int i = 0 ; i < n ; i++ )
        {
            flex += nums[i];
            jump = min(jump,flex);
            if(flex > 0) flex = 0;
        }

        int ans = maxi;
        if(flag == 1)
        {
            ans = max(ans,sum-jump);
        }
        return ans;
    }
};