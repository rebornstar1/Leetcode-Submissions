class Solution {
public:
    // int cntDistance(string &word1, string &word2, int i, int j, vector<vector<int>>&dp)
    // {
    //     // Base Case is yet to be decided
    //     if(j == word2.size())
    //     {
    //         return (word1.size()-i); 
    //     }

    //     if(i == word1.size())
    //     {
    //         return (word2.size()-j);
    //     }

    //     if(dp[i][j] != -1)
    //     {
    //         return dp[i][j];
    //     }

    //     if(word1[i] == word2[j])
    //     {
    //         return dp[i][j] = cntDistance(word1,word2,i+1,j+1,dp); // Next Traversal
    //     }
    //     else
    //     {
    //         return dp[i][j] = (1+min({cntDistance(word1,word2,i+1,j+1,dp),cntDistance(word1,word2,i+1,j,dp),cntDistance(word1,word2,i,j+1,dp)}));
    //     }
    // }

    int minDistance(string word1, string word2) {
        // Think About the Tabulation Approach in this question
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        // Base Case
        for(int i = 0 ; i < n ; i++ ) dp[i][word2.size()] = (word1.size()-i);
        for(int j = 0 ; j < m ; j++ ) dp[word1.size()][j] = (word2.size()-j);

        // for(int i = 0 ; i <= n ; i++ )
        // {
        //     for(int j = 0 ; j <= m ; j++ )
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        // cout<<endl;
        // cout<<endl;

        for(int i = (n-1) ; i >= 0 ; i-- )
        {
            for(int j = (m-1) ; j >= 0 ; j-- )
            {
                if(word1[i] == word2[j]) // Same Character
                {
                    dp[i][j] = dp[i+1][j+1];
                }
                else
                {
                    dp[i][j] = (1 + min({dp[i+1][j+1],dp[i+1][j],dp[i][j+1]}));
                }
            }
        }

        // for(int i = 0 ; i <= n ; i++ )
        // {
        //     for(int j = 0 ; j <= m ; j++ )
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return dp[0][0];
    }
};