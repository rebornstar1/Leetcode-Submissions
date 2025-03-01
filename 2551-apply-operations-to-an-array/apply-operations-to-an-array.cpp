class Solution {
public:
    // If nums[i] == nums[i+1] is present here

    vector<int> applyOperations(vector<int>& nums) {
        // Naive Approach would be to create the Another Array and do these changes in that
        // But I guess the optimal solution would be to make changes inplace

        int n = nums.size();
        int temp = 0;
        int cnt = 0;
        for(int i = 0 ; i < (n-1) ; i++ )
        {
            cout<<i<<" ";
            if(nums[i] == 0)
            {
                cnt++;
                continue;
            }
            else if(nums[i] == nums[i+1])
            {
                nums[temp] = (nums[i]*2);
                i++;
                cnt++;
            }
            else
            {
                nums[temp] = nums[i];
            }
            temp++;
        }
        nums[temp] = nums[n-1];

        for(int i = (n-1) ; i >= 0 ; i-- )
        {
            if(cnt > 0)
            {
                nums[i] = 0;
                cnt--;
            }
        }
        return nums;
    }
};