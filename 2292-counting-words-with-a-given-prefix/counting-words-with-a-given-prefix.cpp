class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int pref_size = pref.size();
        int n = words.size();
        int cnt = 0;
        for(int i = 0 ; i < n ; i++ )
        {
            if(words[i].size() < pref_size) continue;

            if(words[i].substr(0,pref_size) == pref) cnt++;
        }
        return cnt;
    }
};