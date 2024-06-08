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

        vector<int>pres(m+2,0);
        vector<int>nxt(m+2,0);
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        // Base Case
        for(int i = 0 ; i < m ; i++ ) nxt[i] = (word2.size()-i);


        for(int i = n ; i >= 0 ; i-- )
        {
            for(int j = m ; j >= 0 ; j-- )
            {
                pres[word2.size()] = (word1.size()-i);
                if(word1[i] == word2[j]) // Same Character
                {
                    pres[j] = nxt[j+1];
                }
                else
                {
                    pres[j] = (1 + min({nxt[j+1],nxt[j],pres[j+1]}));
                }
            }
            nxt = pres;
        }

        for(auto it : pres)
        {
            cout<<it<<" ";
        }
        return nxt[0];
    }
};

// Now Optimise This code with the Space Optimization