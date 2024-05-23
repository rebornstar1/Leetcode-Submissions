class Solution {
public:
    int NumberSubset(vector<int>& nums, int ind, int k,unordered_map<int,int>&mp)
    {
        if(ind == nums.size())
        {
           return 1;
        }
        int val = 0;
        val += NumberSubset(nums,ind+1,k,mp);
        if(mp[nums[ind]-k] == 0 && mp[nums[ind]+k] == 0)
        {
            // If There is No Overlapping
            mp[nums[ind]]++;
            val += NumberSubset(nums,ind+1,k,mp);
            mp[nums[ind]]--;
        }
        return val;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>dp(nums.size()+1,-1);
        return NumberSubset(nums,0,k,mp)-1;
    }
};