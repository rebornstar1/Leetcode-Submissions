class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int n = s.size(); // size of the string

        vector<int>a(max(t+30,30),0);
        for(int i = 0 ; i < 26 ; i++ ) a[i]++;

        for(int i = 0 ; i < t ; i++ )
        {
            a[i+26] = (a[i]+a[i+1])%1000000007;
        }        

        int ans = 0;
        for(int i = 0  ; i < n ; i++ )
        {
            ans = (ans + a[s[i]-'a'+t])%1000000007;
        }

        return ans;
    }
};

// length of string after t transformations
// O(26*10^5) should be the time complexity of this ideally

// we can think of breaking up everything in terms of the a and b in this