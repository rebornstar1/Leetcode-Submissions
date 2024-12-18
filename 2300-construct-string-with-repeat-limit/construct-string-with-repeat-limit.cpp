class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int N = s.size();
        vector<int>count(26,0);
        string ans;
        for(int i = 0 ; i < N ; i++ )
        {
            count[s[i]-'a']++;
        }

        int i = 24, j = 25;
        
        while(i > 0)
        {
            while(count[j] == 0)
            {
                j = i;
                i--;
                if( i <= 0 ) break;
            }

            while(count[i] == 0)
            {
                if( i <= 0 ) break;
                i--;
            }

            while(count[j] != 0 && count[i] != 0)
            {
                for(int k = 0 ; k < min(count[j],repeatLimit) ; k++ ) ans += ('a'+j);
                if(count[j] > repeatLimit)
                {
                   ans += ('a'+i);
                   count[i]--;
                } 
                count[j] = max(count[j]-repeatLimit,0);
            }
            cout<<ans<<" "<<i<<" "<<j<<" "<<count[i]<<" "<<count[j]<<endl;
        }

        int ct1 = 0;
        while(j>=0 && count[j] != 0 && (ct1 != repeatLimit))
        {
            ans += (j+'a');
            count[j]--;
            ct1++;
        }

        int ct2 = 0;
        while(i>=0 && count[i] != 0 && (ct2 != repeatLimit))
        {
            ans += (i+'a');
            count[i]--;
            ct2++;
        }
        return ans;
    }
};