// class Solution {
// public:
//     long long solve(vector<int>&strength, int x, int terms, int k,int bits)
//     {
//         if(terms == strength.size()) return 0;

//         long long val = INT_MAX;
//         for(int i = 0 ; i < strength.size() ; i++ )
//         {
//             if(!((bits >> i) | 0))
//             {
//                 if(strength[i]%x == 0)
//                 {
//                   val = min(val,((long long)strength[i]/x) + solve(strength, x+k, terms+1 , k, bits |= (1 << i)));
//                 }
//                 else
//                 {
//                   val = min(val,((long long)strength[i]/x + 1) + solve(strength, x+k, terms+1, k, bits |= (1 << i)));
//                 }
//             }
//         }
//         return val;
//     }

//     int findMinimumTime(vector<int>& strength, int k) {
//         int n = strength.size();
//         int x = 1, time = 0;
//         return solve(strength,x,0,k,0);
//     }
// };

class Solution {
public:
    unordered_map<int, unordered_map<int, int>> memo; // Memoization table

    int solve(vector<int>& strength, int x, int terms, int k, int bits) {
        if (terms == strength.size()) return 0; // Base case: all terms used
        if (memo[bits].count(x)) return memo[bits][x]; // Check memoization
        
        int val = INT_MAX;
        for (int i = 0; i < strength.size(); i++) {
            if ((bits >> i) & 1) continue; // Skip if the i-th bit is set (already used)

            // Set the i-th bit
            int newBits = bits | (1 << i);
            
            // Time calculation
            int time = (strength[i] + x - 1) / x;
            val = min(val, time + solve(strength, x + k, terms + 1, k, newBits));
        }

        return memo[bits][x] = val; // Store result in memoization table
    }

    int findMinimumTime(vector<int>& strength, int k) {
        return solve(strength, 1, 0, k, 0);
    }
};


// Apply the Bitmasking here