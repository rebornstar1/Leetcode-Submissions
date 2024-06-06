class Solution {
public:
    int cntSteps(string word1,string word2,int i,int j,vector<vector<int>>&dp)
    {

        if(i == word1.size() || j == word2.size())
        {
            return (word1.size()+word2.size()-i-j);
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        if(word1[i] == word2[j])
        {
            return dp[i][j] = cntSteps(word1,word2,i+1,j+1,dp);
        }
        else
        {
           return dp[i][j] = 1+min(cntSteps(word1,word2,i,j+1,dp),cntSteps(word1,word2,i+1,j,dp));
        }
    }

    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return cntSteps(word1,word2,i,j,dp);
    }
};