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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 1;
        map<long long,int>mp;
        queue<pair<long long,TreeNode*>>qst;
        qst.push({0,root});
        mp[0]++;

        while(!qst.empty())
        {
            auto it = mp.end();
            auto ti = mp.begin();
            int ycomb = ti->first;
            it--;
            ans = max(ans,it->first-ti->first+1);
            // Here I need to change the way in which This is being evaluated
            mp.clear();
            int n = qst.size();
            for(int i = 0 ; i < n ; i++ )
            {
                TreeNode* temp = qst.front().second;
                long long check = (qst.front().first-ycomb);

                if(temp->left != NULL)
                {
                   qst.push({2*check+1,temp->left});
                   mp[2*check+1]++;
                }

                if(temp->right != NULL)
                {
                   qst.push({2*check+2,temp->right});
                   mp[2*check+2]++;
                }
                qst.pop();
            }
        }
        return (int)ans;
    }
};

// Here we will count the NULL Nodes too in the calculation