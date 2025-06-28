class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();

        vector<int>hashValues;
        int hash = 0;
        int b = 256, p = 101;
        for(int i = 0 ; i < n ; i++ )
        {
           hash = (hash*b + (int)s[i])%p;
           hashValues.push_back(hash);
        }

        // also I will be interested in caculating the reverse Hash values

        vector<int>reverseHash;
        int revhash = 0;
        int flex = 1;
        for(int i = (n-1) ; i >= 0 ; i-- )
        {
            revhash = (flex*s[i] + revhash)%p;
            flex = (flex * b)%p; 
            reverseHash.push_back(revhash);
        }

        for(int i = (n-2) ; i >= 0 ; i-- )
        {
           if(hashValues[i] == reverseHash[i])
           {
              // now compare the strings and if those are equal then just return it here itself
              string str1 = s.substr(0,i+1);
              string str2 = s.substr(n-i-1,i+1);
              if(str1 == str2) return str1;
           }
        }

        return "";
    }
};