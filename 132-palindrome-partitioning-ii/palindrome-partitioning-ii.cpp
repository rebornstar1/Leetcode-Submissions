class Solution {
public:
    bool checkPalindrome(string &s,int i,int j)
    {
        while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
        }
        return true;
    }

    int cntCut(string &s,int i,vector<int>&dp)
    {
        if(i == s.size() ) return 0;
        if(dp[i] != -1) return dp[i];

        int mini = INT_MAX;
        for(int k = i ; k < s.size() ; k++ )
        {
            if(checkPalindrome(s,i,k))
            {
                int val = (1+cntCut(s,k+1,dp));
                mini = min(val,mini);
            }
        }
        return dp[i] = mini;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n+1,-1);
        return cntCut(s,0,dp)-1;
    }
};

// Recursion is correct but we need to care about the time commplexity