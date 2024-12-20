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
    TreeNode* reverseOddLevels(TreeNode* root) {
        // Applying BFS here
        int level = 0;
        queue<TreeNode*>qst;
        qst.push(root);

        vector<int>temp;
        while(!qst.empty())
        {
            if(level%2 == 1)
            {
                int N = qst.size();
                int ind = temp.size()-1;
                while(N--)
                {
                    TreeNode* node = qst.front();
                    qst.pop();
                    node->val = temp[ind];
                    ind--;
                    if(node->left != NULL)
                    {
                        qst.push(node->left);
                        qst.push(node->right);
                    }
                }
                temp.clear();
                level++;
            }
            else
            {
                int N = qst.size();
                while(N--)
                {
                    TreeNode* node = qst.front();
                    qst.pop();
                    if(node->left != NULL)
                    {
                        temp.push_back(node->left->val);
                        temp.push_back(node->right->val);
                        qst.push(node->left);
                        qst.push(node->right);
                    }
                }
                // reverse(temp.begin(),temp.end());
               
                level++;
            }
        }
        return root;
    }
};