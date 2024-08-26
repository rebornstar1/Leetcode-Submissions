/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    vector<int>ans;
public:
    void cntPostOrder(Node* root)
    {
        if(root == NULL) return;
        vector<Node*>temp = root->children;
        for(auto it : temp)
        {
            cntPostOrder(it);
        }
        ans.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        cntPostOrder(root);
        return ans;
    }
};