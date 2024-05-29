class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Follow Up Question is about Single PASS
        int n = nums.size();
        int ind = 0, val = (n-1);
        for(int i = 0 ; i < n ; i++ )
        {
            if(nums[i] == 0)
            {
                if(i>ind)
                {
                swap(nums[ind],nums[i]);
                ind++;
                i-=1;
                }
                else
                {
                    ind++;
                }
            }
            if(nums[i] == 2)
            {
                if(i<val)
                {
                  swap(nums[val],nums[i]);
                  val--;
                  i-=1;
                }
                else
                {
                    val--;
                }
            }
        }
    }
};