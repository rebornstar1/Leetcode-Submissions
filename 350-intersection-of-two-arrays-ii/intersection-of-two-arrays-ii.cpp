class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        unordered_map<int,int>dp;
        vector<int>ans;
        for(int i = 0 ; i < nums1.size() ; i++ ) mp[nums1[i]]++;
        for(int i = 0 ; i < nums2.size() ; i++ ) dp[nums2[i]]++;

        for(auto it : mp)
        {
            int val = min(dp[it.first],it.second);
            while(val--)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};