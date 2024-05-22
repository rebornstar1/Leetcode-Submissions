class Solution {
public:
    void Permutation(vector<int>nums,int ind,vector<int>temp,vector<vector<int>>&ans,vector<int>visited)
    {
        if(ind == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        map<int,int>mp;
        for(int i = 0 ; i < nums.size() ; i++ )
        {
            // Here I Need To Make sure that Only Unique's Should be Passed
            if(visited[i] == 0 && mp[nums[i]]==0)
            {
               visited[i] = 1;
               temp.push_back(nums[i]);
               mp[nums[i]]++;
               Permutation(nums,ind+1,temp,ans,visited);
               visited[i] = 0;
               temp.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>visited(nums.size()+1,0);

        Permutation(nums,0,temp,ans,visited);
        // vector<vector<int>>flex;
        // for(auto it : ans)
        // {
        //     flex.push_back(it);
        // }
        return ans;
    }
};

// Now You need to Optimize This Code Right Now