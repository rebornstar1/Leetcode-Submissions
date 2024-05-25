class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++ )
        {
            int k = i;
            while(1)
            {
               if(nums[k] > 0 && nums[k] <= nums.size() && (nums[k]!=(nums[nums[k]-1])))
                {
                    swap(nums[k],nums[nums[k]-1]);
                }
                else
                {
                    break;
                }
            }
        }
        for(int i = 0 ; i < nums.size() ; i++ )
        {
            if(nums[i] != (i+1))
            {
                return (i+1);
            }
        }
        return nums.size()+1;
    }
};