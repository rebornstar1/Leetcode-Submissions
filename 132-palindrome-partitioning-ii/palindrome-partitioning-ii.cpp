class Solution {
public:
    bool checkPalindrome(string s)
    {
        int n = s.size();
        for(int i = 0 ; i < n ; i++ )
        {
            if(s[i]!=s[n-i-1])
            {
                return false;
            }
        }
        return true;
    }

    int Partition(string s,int ind,vector<int>&dp)
    {
        if(ind == s.size())
        {
            return 0;
        }
        if(dp[ind] != -1)
        {
            return dp[ind];
        }
        int val = INT_MAX;
        for(int i = (s.size()-1) ; i >= ind ; i-- )
        {
            if(checkPalindrome(s.substr(ind,i-ind+1)))
            {
                int temp = (1+Partition(s,i+1,dp));
                if(temp > val)
                {
                    break;
                }
                val = temp;
               // val = min(1+Partition(s,i+1,dp),val);
            }
        }
        return dp[ind] = val;
    }


    int minCut(string s) {
        int cnt = 0;
        vector<int>dp(s.size()+1,-1);
        return Partition(s,0,dp)-1;
    }
};