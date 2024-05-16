class Solution {
public:
   // We have to find the sum for every substring possible

    int beautySum(string s) {
        vector<vector<int>>prefix(s.size(),vector<int>(26,0));
        // we will pre evaluate the values
        prefix[0][s[0]-'a']++;
        for(int i = 1 ; i < s.size() ; i++ )
        {
            prefix[i] = prefix [i-1];
            prefix[i][s[i]-'a']++;
        }
        int ans = 0;
        for(int j = 1 ; j <= s.size() ; j++)
        {
           for(int k = 0 ; k < (s.size()-j+1) ; k++ )
           {
                //string p = s.substr(k,j);
                //cout<<p<<endl;
                vector<int>tp(26,0);
                for(int i = 0 ; i < 26 ; i++ )
                {
                    if(k == 0)
                    {
                       tp[i] = prefix[k+j-1][i];
                    }
                    else
                    {
                       tp[i] = (prefix[k+j-1][i]-prefix[k-1][i]);
                    }
                }
                // for(int i = 0 ; i < p.size() ; i++ )
                // {
                //     tp[p[i]-'a']++;
                // }
                sort(tp.begin(),tp.end());
                int val = tp[25];
                int pp = INT_MAX;
                for(int i = 25 ; i >= 0 ; i-- )
                {
                if(tp[i]!=0)
                {
                    pp = min(pp,tp[i]);
                } 
                }
                ans += (val-pp);
           }
        }
        return ans;
    }
};