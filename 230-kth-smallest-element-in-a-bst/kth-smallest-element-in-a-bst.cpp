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
    vector<int>preOrder;
public:
    void solve(TreeNode* root)
    {
        if(root == NULL) return;

        solve(root->left);
        preOrder.push_back(root->val);
        solve(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
          solve(root);
        //   for(auto it : preOrder) cout<<it<<" ";
          return preOrder[k-1];
    }
};

// write the pre order traversal