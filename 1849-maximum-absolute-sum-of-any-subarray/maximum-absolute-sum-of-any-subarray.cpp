class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = 0, temp = 0, tempflex = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++ )
        {
            temp += nums[i];
            if(temp < 0) temp = 0;
            ans = max(ans,temp);
            nums[i] *= -1;
            tempflex += nums[i];
            if(tempflex < 0) tempflex = 0;
            ans = max(ans,tempflex);
        }
        return ans;
    }
};