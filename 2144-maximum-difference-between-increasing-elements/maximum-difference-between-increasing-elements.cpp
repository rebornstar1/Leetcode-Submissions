class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int val = INT_MAX, ans = INT_MIN;
        for(int i = 0 ; i < n ; i++ )
        {
            ans = max(ans,nums[i]-val);
            val = min(val,nums[i]);
        }

        return (ans > 0 ? ans : -1);
    }
};