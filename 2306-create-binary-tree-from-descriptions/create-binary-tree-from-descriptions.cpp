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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
      unordered_map<int,TreeNode*>unique;
      unordered_map<int,int>flag;
      int n = descriptions.size();
      for(auto it : descriptions)
      {
         int a = it[0];
         int b = it[1];
         int c = it[2];

         flag[b]++;

         TreeNode* temp = unique[a];
         if(unique[a] == NULL) temp = new TreeNode(a);
         TreeNode* flex = unique[b];
         if(unique[b] == NULL) flex = new TreeNode(b);

         unique[a] = temp;
         unique[b] = flex;
        
         if(c == 1)
         {
            temp->left = flex;
         }
         else
         {
            temp->right = flex;
         }
      }
      
      for(auto it : unique)
      {
         if(flag[it.first] == 0)
         {
            return it.second;
         }
      }
      return NULL;
    }
};

// NULL is returning Successfully