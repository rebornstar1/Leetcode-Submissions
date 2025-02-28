class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        unordered_map<int,int>mp;
        for(int i = 0 ; i < n ; i++ )
        {
            mp[arr[i]] += (i+1);
        }

        int ans = 0;

        for(int i = (n-2) ; i >= 0 ; i-- )
        {
            if (i + 2 + ans < 3) break;
            
            for(int j = (i+1) ; j < n ; j++ )
            {   
                if (n - j + ans < 2) break;

                if(mp.find(arr[i]+arr[j]) != mp.end())
                {
                   auto it = mp.find(arr[i]+arr[j]);
                   dp[i][j] = (1+dp[j][it->second-1]);
                } 
                ans = max(ans,dp[i][j]);
            }
        }

        if(ans == 0 ) return 0;
        return ans+2;
    }
};