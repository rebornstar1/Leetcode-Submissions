class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        reverse(nums.begin(),nums.end());

        k %= n;

        // do something for first k values
        for(int i = 0 ; i < (k/2) ; i++ )
        {
            swap(nums[i],nums[k-1-i]);
        }

        // do something after k >= values
        for(int i = k ; i < k+(n-k)/2 ; i++ )
        {
            swap(nums[i],nums[n-1-i+k]);
        }
    }
};
// do it in place here