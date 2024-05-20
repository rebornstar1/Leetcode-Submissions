class Solution {
public:
    int ans = 0;
    void func(vector<int>&nums,int index,int value)
    {
       if(index == nums.size())
       {
        ans+=value;
        return;
       }
       func(nums,index+1,value); // Not Take Anything
       func(nums,index+1,value^nums[index]);
    }

    int subsetXORSum(vector<int>& nums) {
        // Apply recursion here (Take/Not Take Approach to be applied)
        func(nums,0,0);
        return ans;
    }
};