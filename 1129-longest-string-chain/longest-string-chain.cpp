class Solution {
private:
    static bool cmp(string &a,string &b)
    {
        return a.size() < b.size();
    }
     

public:
    bool checkfunc(string a,string b)
    {
        int flag = 0;
        // The Size of both the strings should be equal
        if(a.size() != (b.size()-1)) return false;
        for(int i = 0 ; i < a.size() ; i++ )
        {
            if(flag == 0)
            {
                if(a[i] != b[i]) flag = 1;
            }

            if(flag == 1)
            {
                if(a[i] != b[i+1]) return false;
            }
        }
        return true;
    }

    int longestStrChain(vector<string>& words) {

        // first sort the words according to the size
        int n = words.size();
        sort(words.begin(),words.end(),cmp);
        vector<int>dp(n+1,1);

        for(auto it : words)
        {
            cout<<it<<" ";
        }

        int ans = 1;
        for(int i = (n-2) ; i >= 0 ; i-- )
        {
            for(int j = (i+1) ; j < n ; j++ )
            {
                if(checkfunc(words[i],words[j]))
                {
                   cout<<i<<" "<<j<<endl;
                   dp[i] = max(dp[j]+1,dp[i]);
                }
                else if(words[i].size() > (words[j].size()+1))
                {
                    break;
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};

// Very Much Needed To Optimise This Code