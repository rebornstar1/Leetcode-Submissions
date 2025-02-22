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
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        unordered_map<int,TreeNode*>mp;

        vector<pair<int,int>>vp;
        int depth = 0, val = 0;
        for(int i = 0 ; i < n ; i++ )
        {
            if(traversal[i] == '-')
            {
                if(val == 0) depth++;
                else
                {
                    vp.push_back({val,depth});
                    depth = 1;
                    val = 0;
                }
            }
            else
            {
                val *= 10;
                val += (traversal[i]-'0');
            }
        }

        if(n > 1) vp.push_back({val,depth});

        // for(int i = 0 ; i < vp.size() ; i++ )
        // {
        //     cout<<vp[i].first<<" "<<vp[i].second<<endl;
        // }

        // Correct Till This Point

        if(vp.size() == 0) return new TreeNode(stoi(traversal));

        TreeNode* root = new TreeNode(vp[0].first);
        mp[0] = root;

        

        for(int i = 1 ; i < vp.size() ; i++ )
        {
            int jump = vp[i].second;
            int flex = vp[i].first;

            cout<<jump<<" "<<flex<<endl;

            if(mp[jump-1]->left == NULL)
            {
                TreeNode* flip = new TreeNode(flex);
                mp[jump-1]->left = flip;
                mp[jump] = flip;
            }
            else if(mp[jump-1]->right == NULL)
            {
               TreeNode* flip = new TreeNode(flex);
                mp[jump-1]->right = flip;
                mp[jump] = flip;
            }
        }

        return root;
    }
};