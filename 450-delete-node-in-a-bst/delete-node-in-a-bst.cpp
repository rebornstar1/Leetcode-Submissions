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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key) 
        {
            if(root->right == NULL)
            {
                return root->left;
            }   
            else if(root->left == NULL)
            {
                return root->right;
            }
            else
            {
                TreeNode* temp = root->left;
                //root->left = NULL;
                TreeNode* check = root->right;
                TreeNode* flex = check;
                if(check == NULL)
                {
                    cout<<"yes"<<endl;
                    return temp;
                }
                while(check->left != NULL)
                {
                    check = check->left;
                }
                check->left = temp;
                return flex;

            }
        }

        
        if(root->left) root->left = deleteNode(root->left,key);
        if(root->right) root->right = deleteNode(root->right,key);
        return root;
    }
};