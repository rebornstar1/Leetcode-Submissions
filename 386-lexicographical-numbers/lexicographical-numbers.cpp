class Solution {
public:
    vector<int> lexicalOrder(int n) {
        // Naive Approach
       vector<string>vect;
       for(int i = 1 ; i <= n ; i++ )
       {
          vect.push_back(to_string(i));
       }      
       sort(vect.begin(),vect.end());

       vector<int>ans;
       for(int i = 0 ; i < vect.size() ; i++ )
       {
           ans.push_back(stoi(vect[i]));
       }
       return ans;
    }
};