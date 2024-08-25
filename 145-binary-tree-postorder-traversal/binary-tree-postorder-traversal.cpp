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
    vector<int>ans;
public:
    void findPostOrder(TreeNode* root)
    {
        if(root == NULL) return;
        
        findPostOrder(root->left);
        findPostOrder(root->right);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
       findPostOrder(root);
       return ans;
    }
};