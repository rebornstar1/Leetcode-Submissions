class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int>count(26,0);
        for(int i = 0 ; i < s.size() ; i++ )
        {
            count[s[i]-'a']++;
        }

        int cnt = 0;
        for(int i = 0 ; i < 26 ; i++ )
        {
            if(count[i]%2 == 1)  cnt++;
        }
        
        return (cnt <= k) && (s.size() >= k);
    }
};