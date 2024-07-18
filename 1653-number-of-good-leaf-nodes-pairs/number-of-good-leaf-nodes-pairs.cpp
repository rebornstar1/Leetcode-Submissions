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
     vector<string>temp;
public:
    void dfs(TreeNode* root,string check)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL)
        {
            temp.push_back(check);
            return;
        }

        dfs(root->left,check+'L');
        dfs(root->right,check+'R');
    }

    bool check(string s,string p,int distance)
    {
        int val = 0;
        int n = min(s.length(),p.length());
        int flag = 1;
        for(int i = 0 ; i < n ; i++ )
        {
            if(s[i] != p[i]) flag = 0;

            if(flag == 0) val += 2;
        }
        val += (s.length()+p.length()-2*n);
        return val<=distance;
    }

    int countPairs(TreeNode* root, int distance) {
        dfs(root,"");
         int ans = 0;
         for(int i = 0 ; i < temp.size() ; i++ )
         {
            for(int j = (i+1) ; j < temp.size() ; j++ )
            {
               ans += check(temp[i],temp[j],distance);
            }
         }
        return ans;
    }
};