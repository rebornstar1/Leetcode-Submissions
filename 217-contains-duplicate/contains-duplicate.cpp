class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(int i = 0 ; i < n ; i++ ) st.insert(nums[i]);
        return st.size() != n;
    }
};