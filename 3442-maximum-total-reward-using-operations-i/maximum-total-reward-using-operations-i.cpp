class Solution {
public:
    int maxi = INT_MAX;
    int cntValues(vector<int>& rewardValues, int ind,int x, vector<vector<int>>&dp)
    {
       if(ind == rewardValues.size() || x > maxi)
       {
          return 0;
       }
        
        if(dp[ind][x] != -1)
        {
            return dp[ind][x];
        }
        
         if(rewardValues[ind] > x)
         {
              return  dp[ind][x] = max(cntValues(rewardValues,ind+1,x,dp),rewardValues[ind]+cntValues(rewardValues,ind+1,x+rewardValues[ind],dp));
         }
        else
        {
           return dp[ind][x] = cntValues(rewardValues,ind+1,x,dp);
        }
    }
    
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        sort(rewardValues.begin(),rewardValues.end());
        for(int i = 0 ; i < n ; i++ )
        {
            maxi = max(maxi,rewardValues[i]);
        }
        vector<vector<int>>dp(n+5,vector<int>(4020,-1));
        return  cntValues(rewardValues,0,0,dp);
    }

};