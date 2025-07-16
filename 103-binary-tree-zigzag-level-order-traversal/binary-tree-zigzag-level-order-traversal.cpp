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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // we can solve this question with the help of the two stacks correspondingly
        if(root == NULL) return {};

        stack<TreeNode*>st1,st2;
        st1.push(root);
        int even = 0;
        vector<vector<int>>ans;
        ans.push_back({root->val});

        while(!st1.empty() || !st2.empty())
        {
            vector<int>temp;
            if(even%2 == 0)
            {
                while(!st1.empty())
                {
                    TreeNode* topNode = st1.top();
                    st1.pop();

                    if(topNode->right != NULL)
                    {
                        st2.push(topNode->right);
                        temp.push_back(topNode->right->val);
                    }

                    if(topNode->left != NULL)
                    {
                        st2.push(topNode->left);
                        temp.push_back(topNode->left->val);
                    } 
                }
            }
            else
            {
                while(!st2.empty())
                {
                    TreeNode* topNode = st2.top();
                    st2.pop();

                    if(topNode->left != NULL)
                    {
                        st1.push(topNode->left);
                        temp.push_back(topNode->left->val);
                    }

                    if(topNode->right != NULL)
                    {
                        st1.push(topNode->right);
                        temp.push_back(topNode->right->val);
                    } 
                }
            }

            if(temp.size() == 0) break;

            ans.push_back(temp);
            even++;
        }
        return ans;
    }
};

// check if any edge cases are remaining in this problem ?

