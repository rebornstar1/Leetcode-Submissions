class Solution {
private:
    int i = 0, j = 0;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* node = new TreeNode(preorder[i++]);
        if (node->val != postorder[j]) {
            node->left = constructFromPrePost(preorder, postorder);
        }
        if (node->val != postorder[j]) {
            node->right = constructFromPrePost(preorder, postorder);
        }
        j++; // Postorder element matched; move forward
        return node;
    }
};
