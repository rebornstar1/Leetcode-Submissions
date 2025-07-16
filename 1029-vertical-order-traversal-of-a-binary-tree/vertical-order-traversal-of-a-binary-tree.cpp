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
    void dfs(TreeNode* root, int &leftMost, int &rightMost, int i)
    {
        leftMost = min(leftMost,i);
        rightMost = max(rightMost,i);

        if(root->left != NULL) dfs(root->left,leftMost,rightMost,i-1);
        if(root->right != NULL) dfs(root->right,leftMost,rightMost,i+1);
        return;
    }

    int height(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // apply dfs and find the left most and the right most for the root
        int leftMost = 0, rightMost = 0;
        int maxHeight = height(root);
        dfs(root,leftMost,rightMost,0);
        int root_count = 0;
        root_count -= leftMost;

        vector<vector<vector<int>>>ans(rightMost-leftMost+1,vector<vector<int>>(maxHeight+1));
        queue<pair<vector<int>,TreeNode*>>qst;
        qst.push({{root_count,0},root});

        while(!qst.empty())
        {
            int r = qst.front().first[0];
            int c = qst.front().first[1];
            TreeNode* node = qst.front().second;
            ans[r][c].push_back(node->val);
            qst.pop();

            if(node->left != NULL)
            {
               qst.push({{r-1,c+1},node->left});
            }

            if(node->right != NULL)
            {
                qst.push({{r+1,c+1},node->right});
            }
        }

        for(int i = 0 ; i < ans.size() ; i++ )
        {
            for(int j = 0 ; j < ans[i].size() ; j++ )
            {
                sort(ans[i][j].begin(),ans[i][j].end());
            }
        }

        vector<vector<int>>flex;
        for(int i = 0 ; i < ans.size() ; i++ )
        {
            vector<int>champ;
            for(int j = 0 ; j < ans[i].size() ; j++ )
            {
                for(int k = 0 ; k < ans[i][j].size() ; k++ )
                {
                    champ.push_back(ans[i][j][k]);
                }
            }
            flex.push_back(champ);
        }

        return flex;
    }
};