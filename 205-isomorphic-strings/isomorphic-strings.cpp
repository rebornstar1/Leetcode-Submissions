class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<char>vect(256,'#');
        int n = s.size();

        for(int i = 0 ; i < n ; i++ )
        {
            cout<<vect[s[i]]<<" "<<t[i]<<endl;
            if(vect[s[i]] == '#')
            {
                vect[s[i]] = t[i];
            }
            else if(t[i] != vect[s[i]]) return false;
        }

        for(int i = 0 ; i < 256 ; i++ ) vect[i] = '#';

        for(int i = 0 ; i < n ; i++ )
        {
            cout<<vect[t[i]]<<" "<<s[i]<<endl;
            if(vect[t[i]] == '#')
            {
                vect[t[i]] = s[i];
            }
            else if(s[i] != vect[t[i]]) return false;
        }

        return true;
    }
};