class Solution {
public:
    char kthCharacter(int k) {
        // findPow Of Two's
        set<int>powOfTwo;
        int temp = 1;
        for(int i = 1 ; i < 11 ; i++ )
        {
            powOfTwo.insert(temp);
            temp *= 2;
        }

        vector<int>dp(k+1,0);
        dp[0] = 0;
        for(int i = 0 ; i <= k ; i++ )
        {
           auto it = powOfTwo.upper_bound(i);
           int tempVal = (*it);

           while(1)
           {
               if((i+tempVal) <= k)
               {
                  dp[i+tempVal] = (dp[i]+1);
                  tempVal *= 2;
               }
               else
               {
                  break;
               }
           }
        }
        return (dp[k-1]%26+'a');
    }
};