class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxi = nums[0];
        for(int i = 0 ; i < nums.size() ; i++ )
        {
            currSum += nums[i];
            maxi = max(maxi,currSum);
            if(currSum < 0 ) currSum = 0;
        }
        return maxi;
    }
};

// Write the Kadane's Algorithm
