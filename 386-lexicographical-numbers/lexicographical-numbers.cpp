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

// I may try a recursive loop in which I'll prioritly take values in the each digits order itself
// To Be Implemented As soon as I'm up with the Codeforces Contest Now

// Write Algorithm That Runs in O(N) Run Time and O(1) extra space