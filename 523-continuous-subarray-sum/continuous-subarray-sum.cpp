class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2)
        {
            return false;
        }

        unordered_map<int,int>mp;
        mp[0] = -1;

        int val = 0;
        for(int i = 0 ; i < nums.size() ; i++ )
        {
            val += nums[i];
            val = (val%k);

            if(mp.find(val) != mp.end())
            {
                if((i-mp[val])>1)
                {
                    return true;
                }
            }
            else
            {
                mp[val] = i;
            }
        }

        return false;
    }
};