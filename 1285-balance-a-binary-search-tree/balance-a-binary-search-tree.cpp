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
    void inOrder(TreeNode* root, vector<TreeNode*>&test)
    {
        if(root == NULL)
        {
            return;
        }
        inOrder(root->left,test);
        test.push_back(root);
        inOrder(root->right,test);
    }

    TreeNode* createTree(vector<TreeNode*>&test,int st,int en)
    {
        int md = (st+en)/2;
        if(st>en || test[md] == NULL) return NULL;
        test[md]->left = createTree(test,st,md-1);
        test[md]->right = createTree(test,md+1,en);
        return test[md];
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>test;
        inOrder(root,test);
        
        int n = test.size();
        // Now I have this I'll create a Balanced Binary Search Tree
        return createTree(test,0,n-1);
    }
};

// Depth Should be Counted From Below