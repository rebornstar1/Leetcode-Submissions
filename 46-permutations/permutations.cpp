class Solution {
public:
    void Permutation(vector<int>nums,int ind,vector<int>temp,vector<vector<int>>&ans,vector<int>visited)
    {
        if(ind == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i = 0 ; i < nums.size() ; i++ )
        {
            if(visited[i] == 0)
            {
               visited[i] = 1;
               temp.push_back(nums[i]);
               Permutation(nums,ind+1,temp,ans,visited);
               visited[i] = 0;
               temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>visited(nums.size()+1,0);
        Permutation(nums,0,temp,ans,visited);
        return ans;
    }
};