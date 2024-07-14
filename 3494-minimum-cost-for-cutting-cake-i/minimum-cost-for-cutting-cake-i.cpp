class Solution {
public:
    int cntMIN(vector<int>& a, vector<int> &b,int h,int v,int i,int j,vector<vector<int>>&dp)
    {
        if((i == 0) && (j == 0)) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int num = INT_MAX;
        if( i > 0 ) 
        {
           num = min(num, a[i-1]*v + cntMIN(a,b,h+1,v,i-1,j,dp));
        }

        if(j > 0 )
        { 
           num = min(num, b[j-1]*h + cntMIN(a,b,h,v+1,i,j-1,dp));
        }

        return dp[i][j] = num;
    }

    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        
        // 
        sort(horizontalCut.begin(),horizontalCut.end());
        sort(verticalCut.begin(),verticalCut.end());

        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        return cntMIN(horizontalCut,verticalCut,1,1,m-1,n-1,dp);
    }
};