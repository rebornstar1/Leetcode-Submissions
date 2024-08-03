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
    int parent = INT_MIN;
public:
    bool isValid(TreeNode* root,long long l,long long r)
    {
        if(root == NULL)
        {
            return true;
        }

        if(root->val > l && root->val < r)
        {
            return isValid(root->left,l,root->val)&isValid(root->right,root->val,r);
        }
        else
        {
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {
        return isValid(root,-1e10,1e10);
    }
};

// Write the code for Validating Binary Tree