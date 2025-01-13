class Solution {
public:
    int minimumLength(string s) {
        vector<int>freq(26,0);
        for(int i = 0 ; i < s.size() ; i++ )
        {
            freq[s[i]-'a']++;
        }

        int ans = 0;
        for(int i = 0 ; i < 26 ; i++ )
        {
            ans += freq[i]%2;
            if(freq[i]%2 == 0 && freq[i] > 0) ans += 2;
        }
        return ans;
    }
};