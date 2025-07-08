class Solution {
public:
    class TrieNode {
    public:
        TrieNode* children[2] = {nullptr, nullptr};
    };

    void insert(TrieNode* root, int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->children[bit])
                node->children[bit] = new TrieNode();
            node = node->children[bit];
        }
    }

    int getMaxXOR(TrieNode* root, int num) {
        TrieNode* node = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int toggledBit = bit ^ 1;
            if (node->children[toggledBit]) {
                maxXOR |= (1 << i);
                node = node->children[toggledBit];
            } else {
                node = node->children[bit];
            }
        }
        return maxXOR;
    }

    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for (int num : nums) {
            insert(root, num);
        }

        int maxResult = 0;
        for (int num : nums) {
            maxResult = max(maxResult, getMaxXOR(root, num));
        }
        return maxResult;
    }
};
