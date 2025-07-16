class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int one = 0, zero = 0;
        for(int i = 0 ; i < n ; i++ )
        {
            if(nums[i]%2 == 0) zero++;
            else one++;
        }

        int onezero = 0, zerone = 0;
        int tempzero = 1, tempone = 0;

        for(int i = 0 ; i < n ; i++ )
        {
            if(nums[i]%2 == tempzero)
            {
                tempzero ^= 1;
                onezero++;
            }

            if(nums[i]%2 == tempone)
            {
                tempone ^= 1;
                zerone++;
            }
        }

        return max({one,zero,onezero,zerone});
    }
};

// longest valid subsequence
// 00000
// 11111
// 01010
// 10101