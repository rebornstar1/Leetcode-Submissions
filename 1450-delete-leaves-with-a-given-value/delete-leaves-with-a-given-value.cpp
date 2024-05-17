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
    void dfs(TreeNode* &root,int target)
    { 
        if(root == NULL)
        {
            return;
        }  
        dfs(root->left,target);
        dfs(root->right,target);
        if(root->left != NULL)
        {
           if(root->left->val == target && root->left->left == NULL && root->left->right == NULL)
           {
            root->left = NULL;
           }
        }
        if(root->right != NULL)
        {
           if(root->right->val == target && root->right->left == NULL && root->right->right == NULL)
           {
            root->right = NULL;
           }
        }
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        dfs(root,target);
        if(root->val == target && root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        return root;
    }
};