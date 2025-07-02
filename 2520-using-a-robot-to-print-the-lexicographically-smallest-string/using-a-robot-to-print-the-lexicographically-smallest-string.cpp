class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> minSuffix(n);
        
        minSuffix[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            minSuffix[i] = min(s[i], minSuffix[i + 1]);
        }

        string t;
        string res; 

        for (int i = 0; i < n; i++) {
            t.push_back(s[i]);
            while (!t.empty() && (i == n - 1 || t.back() <= minSuffix[i + 1])) {
                res += t.back();
                t.pop_back();
            }
        }

        return res;
    }
};
