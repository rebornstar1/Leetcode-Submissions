class Solution {
public:
    void Permutation(vector<int>nums,int ind,vector<vector<int>>&ans)
    {
        if(ind == (nums.size()-1))
        {
            ans.push_back(nums);
        }
        for(int i = ind ; i < nums.size() ; i++ )
        {
            if(ind!=i)
            {
               if(nums[i]!=nums[ind])
               {
                swap(nums[i],nums[ind]);
                Permutation(nums,ind+1,ans);
               }
            }
            else
            {
                Permutation(nums,ind+1,ans);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        Permutation(nums,0,ans);
        return ans;
    }
};

// Now You need to Optimize This Code Right Now

// (The Much More Optimized Solution for this question is like somewhere)