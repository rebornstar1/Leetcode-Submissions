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
private:
    int max_height = -1;
public:
    void dfs(TreeNode* root, vector<int>&ans,int curr_height)
    {
        // base case
        if(root == NULL) return;

        if(curr_height > max_height )
        {
            ans.push_back(root->val);
            max_height = curr_height;
        }

        if(root->right != NULL) dfs(root->right,ans,curr_height+1);
        if(root->left != NULL) dfs(root->left,ans,curr_height+1);
        return;
    }

    vector<int> rightSideView(TreeNode* root) {
        int curr_height = 0;
        vector<int>ans;
        dfs(root,ans,curr_height);
        return ans;
    }
};