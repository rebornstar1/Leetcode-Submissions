/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL || root == p || root == q) return root;
        if((root->left == p && root->right == q) || (root->left == q && root->right == p)) return root;

        TreeNode* one = lowestCommonAncestor(root->right,p,q);
        TreeNode* two = lowestCommonAncestor(root->left,p,q);

        if(one == NULL) return two;
        if(two == NULL) return one;
        return root;
    }
};

// Try To Optimise This code in terms of Time Complexity and Recursive Calls