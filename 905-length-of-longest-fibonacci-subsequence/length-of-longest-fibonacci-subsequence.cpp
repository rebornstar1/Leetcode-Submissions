// class Solution {
// public:
//     int lenLongestFibSubseq(vector<int>& arr) {
//         int n = arr.size();
//         vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//         unordered_map<int,int>mp;
//         for(int i = 0 ; i < n ; i++ )
//         {
//             mp[arr[i]]+=(i+1);
//         }

//         int ans = 0;

//         for(int i = (n-2) ; i >= 0 ; i-- )
//         {
//             for(int j = (i+1) ; j < n ; j++ )
//             {                
//                 dp[i][j] = ((mp[arr[i]+arr[j]] != 0) ? 1 : 0);
//                 // so basically If the arr[i]+arr[j] exists in the array then you can go for something like 
//                 int index = mp[arr[i]+arr[j]];
//                 if(index > 0)
//                 {
//                     dp[i][j] += dp[j][index-1];
//                     ans = max(ans,dp[i][j]);
//                 }
//             }
//         }

//         if(ans == 0 ) return 0;
//         return ans+2;
//     }
// };

// // I guess we can make it something like the 2 - D DP of dp[i][j]

// // Longest Fibonaaci Subsequence

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        // Only need n×n size, not (n+1)×(n+1)
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Store exact indices for cleaner code
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }
        
        int maxLen = 0;
        
        // We can iterate forward instead of backward (simpler to understand)
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                // Check if the next Fibonacci number exists
                int next = arr[i] + arr[j];
                
                if (mp.find(next) != mp.end()) {
                    int k = mp[next];
                    // Make sure k > j to maintain the sequence order
                    if (k > j) {
                        // dp[j][k] represents length of Fibonacci subsequence
                        dp[j][k] = dp[i][j] + 1;
                        maxLen = max(maxLen, dp[j][k]);
                    }
                }
                
                // Early termination if remaining elements are too few to form a longer sequence
                if (n - j + maxLen < 3) break;
            }
            
            // Early termination for the outer loop
            if (n - i + maxLen < 3) break;
        }
        
        // If maxLen > 0, we found at least one valid Fibonacci sequence
        // Add 2 for the first two elements of the sequence
        return maxLen > 0 ? maxLen + 2 : 0;
    }
};