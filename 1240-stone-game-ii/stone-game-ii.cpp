class Solution {
private:
    int ans = INT_MIN;
public:
    int solve(int m,int flag,int ind,vector<int>&piles,vector<vector<vector<int>>>&dp)
    {
        int n = piles.size();
        if(ind == n)
        {
            return 0;
        }

        if(dp[m][flag][ind] != -1) return dp[m][flag][ind];

        int val = INT_MIN,check = INT_MAX;
        if(flag == 0)
        {
           int sum = 0;
           for(int i = ind ; i < min(ind+2*m,n) ; i++ )
           {
                sum += piles[i];
                val = max(val,sum+solve(max(i-ind+1,m),flag^1,i+1,piles,dp));
           }
           return dp[m][flag][ind] = val;
        }
        else
        {
           for(int i = ind ; i < min(ind+2*m,n) ; i++ )
           {
              check = min(check,solve(max(i-ind+1,m),flag^1,i+1,piles,dp));
           }
           return dp[m][flag][ind] = check;
        }
    }

    int stoneGameII(vector<int>& piles) {
        // a => current score of Alice
        int a = 0;

        // flag 0 => Alice's Turn
        // flag 1 => Bob's Turn  
        int flag = 0; 

        vector<vector<vector<int>>>dp(201,vector<vector<int>>(3,vector<int>(101,-1)));
        return solve(1,flag,0,piles,dp);
    }
};

// At First Writing the Recursive Code Here