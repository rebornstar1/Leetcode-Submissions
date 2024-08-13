class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();
        
        // We Can Apply the Two Pointer Approach in this problem
        int prev = 0, curr = 0, sum = nums[0], ans = INT_MAX;
        while(1)
        {
            if(sum >= target)
            {
               ans = min(ans,curr-prev+1);
               sum-=nums[prev];
               prev++;
            }
            else
            {
              if(curr == (n-1)) break;
              curr++;
              sum += nums[curr];
            }
        }

        if(ans == INT_MAX) return 0;
        return ans;
    }
};