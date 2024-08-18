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
    bool check(TreeNode* root,TreeNode* p)
    {
        if(root == NULL) return false;
        if(root == p) return true;

        return check(root->left,p)|check(root->right,p);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(check(root->left,p)&check(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        if(check(root->right,p)&check(root->right,q)) return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};