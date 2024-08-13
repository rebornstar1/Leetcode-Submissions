class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long sum = nums[0], curr = nums[0], flag = 1;
        // flag 1 represents +ve Sign
        // flag 0 represents -ve Sign
        long long ans = nums[0];
        for(int i = 1 ; i < n ; i++ )
        {
            if(nums[i] > curr)
            {
                if(flag == 1)
                {
                   sum += abs(nums[i]-curr);
                   curr = nums[i];
                }
                else
                {
                   sum += nums[i];
                   curr = nums[i];
                   flag = 1;
                }
            }
            else
            {
                if(flag == 0)
                {
                   sum += abs(nums[i]-curr);
                   curr = nums[i];
                }
                else
                {
                   sum -= nums[i];
                   curr = nums[i];
                   flag = 0;
                }
            }
             
            ans = max(ans,sum);
        }
        return ans;
    }
};