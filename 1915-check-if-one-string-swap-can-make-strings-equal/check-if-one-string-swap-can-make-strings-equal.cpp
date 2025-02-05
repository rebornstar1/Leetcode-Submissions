class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int>freq(26,0);
        int cnt = 0;
        for(int i = 0 ; i < s1.size() ; i++ )
        {
            if(s1[i] != s2[i]) cnt++;

            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
        }

        for(int i = 0 ; i < 26 ; i++ )
        {
            if(freq[i] != 0) return false;
        }

        if(cnt <= 2) return true;
        return false;
    }
};