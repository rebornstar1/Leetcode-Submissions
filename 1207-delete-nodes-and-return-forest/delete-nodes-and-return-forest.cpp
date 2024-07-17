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
    void dfs(TreeNode* root,vector<pair<TreeNode*,TreeNode*>>&ans)
    {
        if(root->left != NULL)
        {
            ans.push_back({root->left,root});
            dfs(root->left,ans);
        }

        if(root->right != NULL)
        {
            ans.push_back({root->right,root});
            dfs(root->right,ans);
        }
    }

    TreeNode* disconnect(TreeNode* root,set<int>&check)
    {
        if(root->left != NULL)
        {
            int temp = root->left->val;
            disconnect(root->left,check);
            if(check.find(temp) != check.end())
            {
                root->left = NULL;
            }
        }
        if(root->right != NULL)
        {
            int temp = root->right->val;
            disconnect(root->right,check);
            if(check.find(temp) != check.end())
            {
                root->right = NULL;
            }
        }
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        set<int>check;
        check.insert(-1);
        for(int i = 0 ; i < to_delete.size() ; i++ ) check.insert(to_delete[i]);
        vector<pair<TreeNode*,TreeNode*>>ans;
        TreeNode* ump = new TreeNode(-1);
        ans.push_back({root,ump});
        dfs(root,ans);

        vector<TreeNode*>jump;
        for(int i = 0 ; i < ans.size() ; i++ )
        {
           TreeNode* node = ans[i].first;
           TreeNode* parent = ans[i].second;

           if((check.find(node->val) == check.end()) && (check.find(parent->val) != check.end()))
           {
              disconnect(node,check);
              jump.push_back(node);
           }
        }
        return jump;
    }
};

// We need to return the childs of to_delete nodes may be 