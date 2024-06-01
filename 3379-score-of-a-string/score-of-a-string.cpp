class Solution {
public:
    int scoreOfString(string s) {
        int val = 0;
        for(int i = 1 ; i < s.size() ; i++ )
        {
           val+=abs(s[i]-s[i-1]);
        }
        return val;
    }
};