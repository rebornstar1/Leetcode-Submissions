class Solution {
public:
    int cntDistance(string &word1, string &word2, int i, int j, vector<vector<int>>&dp)
    {
        // Base Case is yet to be decided
        if(j == word2.size())
        {
            return (word1.size()-i); 
        }

        if(i == word1.size())
        {
            return (word2.size()-j);
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if(word1[i] == word2[j])
        {
            return dp[i][j] = cntDistance(word1,word2,i+1,j+1,dp); // Next Traversal
        }
        else
        {
            return dp[i][j] = (1+min({cntDistance(word1,word2,i+1,j+1,dp),cntDistance(word1,word2,i+1,j,dp),cntDistance(word1,word2,i,j+1,dp)}));
        }
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return cntDistance(word1,word2,0,0,dp);
    }
};