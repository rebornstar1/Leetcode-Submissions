class Solution {
public:
    vector<int>temp;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>val;
        vector<int>gh = {};
        val.push_back(gh);
        check(0,nums,val);
        return val;
    }

    void check(int ind,vector<int>&nums,vector<vector<int>>&val){
        if(ind==nums.size()){
            return;
        }
        temp.push_back(nums[ind]);
        check(ind+1,nums,val);
        val.push_back(temp);
        temp.pop_back();
        check(ind+1,nums,val);
    }
};