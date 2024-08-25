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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        vector<int>ans;
        queue<TreeNode*>qst;
        qst.push(root);
        while(!qst.empty())
        {
           int value = 1e6;
           int n = qst.size();
           for(int i = 0 ; i < n ; i++ )
           {
              TreeNode* temp = qst.front();
              value = temp->val;
              if(temp->left != NULL)
              {
                qst.push(temp->left);
              }

              if(temp->right != NULL)
              {
                qst.push(temp->right);
              }
              qst.pop();
           }
           ans.push_back(value);
        }
        return ans;
    }
};