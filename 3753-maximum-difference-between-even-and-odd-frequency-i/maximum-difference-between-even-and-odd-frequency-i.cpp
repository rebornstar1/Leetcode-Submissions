class Solution {
public:
    int maxDifference(string s) {
        vector<int>freq(26,0);
        int n = s.size();
        for(int i = 0 ; i < n ; i++ )
        {
             freq[s[i]-'a']++;
        }
        
        int eh = INT_MIN, ol = INT_MAX, oh = INT_MIN, el = INT_MAX;
        for(int i = 0 ; i < 26 ; i++ )
        {
           if(freq[i] == 0) continue;
           if(freq[i]%2 == 0)
           {
               eh = max(eh,freq[i]);
               el = min(el,freq[i]);
           }
            else
            {
                oh = max(oh,freq[i]);
                ol = min(ol,freq[i]);
            }
        }
        
        cout<<eh<<" "<<el<<" "<<oh<<" "<<ol<<endl;
        return oh-el;
    }
};