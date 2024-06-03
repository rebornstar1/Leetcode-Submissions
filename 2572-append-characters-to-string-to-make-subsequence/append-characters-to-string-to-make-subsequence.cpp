class Solution {
public:
    int appendCharacters(string s, string t) {
        int a = 0;
        for(int i = 0 ; i < s.size() ; i++ )
        {
            if(s[i] == t[a])
            {
                a++;
            }
        }
        return t.size()-a;
    }
};