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
    map<int,vector<vector<int>>>mp;

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        int check = 0;
        
        queue<pair<vector<int>,TreeNode*>>qst;
        qst.push({{0,0},root});

        while(!qst.empty())
        {
            TreeNode* temp = qst.front().second;
            int a = qst.front().first[0];
            int hp = qst.front().first[1];
            qst.pop();
            
            mp[hp].push_back({a+1,temp->val}); 
            
            if(temp->left != NULL) qst.push({{a,hp-1},temp->left});
            if(temp->right != NULL) qst.push({{a+1,hp+1},temp->right});
        }

        for(auto it : mp)
        {
            sort(it.second.begin(),it.second.end());
            vector<int>check;
            for(auto pp : it.second)
            {
                check.push_back(pp[1]);
            }
            ans.push_back(check);
            
        }
        return ans;
    }
};

// First Write the map solution and then try to optimize it