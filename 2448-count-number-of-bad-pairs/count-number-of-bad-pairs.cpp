class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0 ; i < n ; i++ )
        {
            mp[nums[i]-i]++;
        }
        
        long long ans = 0;
        for(auto it : mp)
        {
            ans += ((n-it.second)*it.second);
        }
        return ans/2;
    }
};