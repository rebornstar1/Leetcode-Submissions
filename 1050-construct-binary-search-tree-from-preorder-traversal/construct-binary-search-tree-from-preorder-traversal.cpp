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
    TreeNode* formBST(TreeNode* root,int key)
    {
        if(key < root->val)
        {
            if(root->left == NULL)
            {
               root->left = new TreeNode(key);
               return root;
            }
            else
            {
                root->left = formBST(root->left,key);
                return root;
            }
        }
        else if(key > root->val)
        {
            if(root->right == NULL)
            {
                root->right = new TreeNode(key);
                return root;
            }
            else
            {
                root->right = formBST(root->right,key);
                return root;
            }
        }

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int n = preorder.size();
        for(int i = 1 ; i < n ; i++ )
        {
            root = formBST(root,preorder[i]);
        }
        return root;
    }
};