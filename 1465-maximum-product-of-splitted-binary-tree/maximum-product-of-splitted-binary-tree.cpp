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
    long long ans = -1;

public:
    int sumOfAll(TreeNode* root)
    {
        if(root == NULL) return 0;
        int sum = root->val;
        if(root->left != NULL) sum += sumOfAll(root->left);
        if(root->right != NULL) sum += sumOfAll(root->right);
        return sum;
    }

    int checkSumOf(TreeNode* root,long long totalSum)
    {
        if(root == NULL) return 0;
        int sum = root->val;
        if(root->left != NULL)
        {
           long long temp = checkSumOf(root->left,totalSum);
           sum += temp;
           ans = max(ans,temp*(totalSum-temp));
        } 
        if(root->right != NULL)
        {
           int temp = checkSumOf(root->right,totalSum);
           sum += temp;
           ans = max(ans,temp*(totalSum-temp));
        } 
        return sum;
    }

    int maxProduct(TreeNode* root) 
    {
        long long totalSum = sumOfAll(root);
        cout<<totalSum<<endl;

        // I might need to create another one function for this purpose
        cout<<checkSumOf(root,totalSum)<<endl;

        return ans%1000000007;
    }
};

// When I'm Witnessing Parent to child condition
// (Total Sum - child sum)* child sum This has to be maximum for our problem