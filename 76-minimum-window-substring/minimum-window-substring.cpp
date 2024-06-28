class Solution {
public:
    bool samewindow(vector<int>&temp,vector<int>&reqcnt)
    {
        for(int i = 0 ; i < 52 ; i++)
        {
           if(temp[i] < reqcnt[i]) return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int>reqcnt(52,0);
        vector<int>temp(52,0);
        for(int i = 0 ; i < m ; i++ )
        {
           if(t[i] >= 'A' && t[i] <= 'Z') reqcnt[t[i]-'A'+26]++;
           if(t[i] >= 'a' && t[i] <= 'z') reqcnt[t[i]-'a']++;
        }
        int prev = 0, curr = 0, flex;
        int vara = INT_MAX;
        while(curr <= n)
        {
            if(samewindow(temp,reqcnt))
            {
               if((curr-prev) < vara){
                vara = (curr-prev);
                flex = prev;
               }
               if(s[prev] >= 'A' && s[prev] <= 'Z') temp[s[prev]-'A'+26]--;
               if(s[prev] >= 'a' && s[prev] <= 'z') temp[s[prev]-'a']--;
               prev++;
            }
            else if(curr < n)
            {
                if(s[curr] >= 'A' && s[curr] <= 'Z') temp[s[curr]-'A'+26]++;
               if(s[curr] >= 'a' && s[curr] <= 'z') temp[s[curr]-'a']++;
                curr++;
            }
            else
            {
                break;
            }
        }
        if(vara == INT_MAX) return "";
        //cout<<vara;
        return s.substr(flex,vara);
    }
};

// Minimum Window Substring