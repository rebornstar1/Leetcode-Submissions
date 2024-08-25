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
    void formGraph(TreeNode* root,vector<vector<int>>&Adj)
    {
        if(root->left != NULL)
        {
            Adj[root->val].push_back(root->left->val);
            Adj[root->left->val].push_back(root->val);
            formGraph(root->left,Adj);
        }

        if(root->right != NULL)
        {
            Adj[root->val].push_back(root->right->val);
            Adj[root->right->val].push_back(root->val);
            formGraph(root->right,Adj);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Create a Graph and Adjacency List out here
        vector<vector<int>>Adj(505);
        formGraph(root,Adj);
        vector<int>Vis(505,0);
        
        vector<int>ans;
        queue<int>qst;
        qst.push(target->val);
        Vis[target->val] = 1;
        if(k == 0)
        {
            ans.push_back(target->val);
        }
        while(!qst.empty() && k != 0)
        {
           int n = qst.size();
           for(int i = 0 ; i < n ; i++ )
           {
               int num = qst.front();
               for(int j = 0 ; j < Adj[num].size() ; j++ )
               {
                  if(Vis[Adj[num][j]] == 0)
                  {
                    qst.push(Adj[num][j]);
                    Vis[Adj[num][j]] = 1;
                  }
               }
               qst.pop();
           }
           k--;
        }

        while(!qst.empty())
        {
            if(qst.front() != target->val)
            {
                ans.push_back(qst.front());
            }
            qst.pop();
        }
        return ans;
    }
};

// First I'll be counting the distance of target from the