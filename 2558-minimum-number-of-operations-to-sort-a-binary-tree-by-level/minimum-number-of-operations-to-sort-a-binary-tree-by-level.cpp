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
   int countOperations(vector<int>& check)
{
    vector<pair<int, int>> flex;
    for (int i = 0; i < check.size(); i++)
    {
        flex.push_back({check[i], i});
    }

    sort(flex.begin(), flex.end());

    vector<bool> visited(check.size(), false);
    int ans = 0;

    for (int i = 0; i < check.size(); i++)
    {
        if (visited[i] || flex[i].second == i)
        {
            continue;
        }
        int cycle_size = 0;
        int j = i;
        while (!visited[j])
        {
            visited[j] = true;
            j = flex[j].second;
            cycle_size++;
        }

        if (cycle_size > 1)
        {
            ans += (cycle_size - 1);
        }
    }
    return ans;
}

    int minimumOperations(TreeNode* root) {
        vector<int>vect;
        vect.push_back(root->val);
        queue<TreeNode*>qst;
        qst.push(root);
        int ans = 0;

        while(!qst.empty())
        {
            int N = qst.size();
            int ind = 0;
            vector<int>temp;
            while(N--)
            {
               TreeNode* node = qst.front();
               qst.pop();
               node->val = vect[ind];
               ind++;

               if(node->left != NULL)
               {
                  temp.push_back(node->left->val);
                  qst.push(node->left);
               }

               if(node->right != NULL)
               {
                  temp.push_back(node->right->val);
                  qst.push(node->right);
               }
            }
            vect = temp;
            for(int i = 0 ; i < vect.size() ; i++ ) cout<<vect[i]<<" ";
            cout<<ans<<" "<<"ans"<<endl;
            ans += countOperations(vect);
            sort(vect.begin(),vect.end());
            for(int i = 0 ; i < vect.size() ; i++ ) cout<<vect[i]<<" ";
            cout<<ans<<" "<<"ans"<<endl;
            cout<<endl;
        }
        return ans;
    }
};

// Apply Merge Sort on This Question to count the number of swaps here