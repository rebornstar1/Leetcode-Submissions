/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructTree(vector<int>& nums, int i, int j)
    {
        if(i > j)
        {
            return NULL;
        }

        int ind = -1, val = INT_MIN;
        for(int k = i ; k <= j ; k++ )
        {
            if(nums[k] > val)
            {
               val = max(val,nums[k]);
               ind = k;
            } 
        }

        TreeNode* root = new TreeNode(val);
        root->left = constructTree(nums,i,ind-1);
        root->right = constructTree(nums,ind+1,j);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return constructTree(nums,0,n-1);
    }
};