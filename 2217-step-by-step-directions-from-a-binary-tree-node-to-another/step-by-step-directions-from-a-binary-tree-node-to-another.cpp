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
    string GetWay(TreeNode* root,int value,string &s)
    {
        if(root == NULL) return "test";
        if(root->val == value) return s;

        s += 'L';
        string temp1 = GetWay(root->left,value,s);
        if(temp1 != "test")
        {
            return temp1;
        }
        s[s.size()-1] = 'R';
        string temp2 = GetWay(root->right,value,s);
        if(temp2 != "test")
        {
            return temp2;
        }
        s.pop_back();
        return "test";
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s = "";
        string a = GetWay(root,startValue,s);
        s= "";
        string b = GetWay(root,destValue,s);

        string ans;
        int ind = 0;
        while(a[ind] == b[ind])
        {
            ind++;
        }
        for(int i = ind ; i < a.size() ; i++ )
        {
            ans += 'U';
        }
        for(int i = ind ; i < b.size() ; i++ )
        {
            ans += b[i];
        }
        return ans;
    }
};

// Check how to optimise this more