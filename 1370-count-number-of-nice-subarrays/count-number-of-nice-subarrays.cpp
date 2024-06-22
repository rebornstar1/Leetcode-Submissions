class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>odd;
        odd.push_back(-1);
        for(int i = 0 ; i < nums.size() ; i++ )
        {
            if(nums[i]%2 == 1)
            {
                odd.push_back(i);
            }
        }
        odd.push_back(n);
        int ans = 0;
        if(odd.size() < k) return 0;
        for(int i = 1 ; i <= (odd.size()-k-1) ; i++ )
        {
            ans += (odd[i]-odd[i-1])*(odd[k+i]-odd[k+i-1]);
        }
        return ans;
    }
};

