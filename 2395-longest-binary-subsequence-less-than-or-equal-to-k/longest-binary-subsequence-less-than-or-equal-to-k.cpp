// class Solution {
// public:
//     int func(int is, int ik, string &s, string &strk, vector<vector<int>> &DP)
//     {
//         if(is == s.size() || ik == strk.size()) return 0;

//         if(DP[is][ik] != -1) return DP[is][ik];

//         if(s[is] == '0')
//         {
//             if(strk[ik] == '0')
//             {
//                if(ik == 0) return DP[is][ik] = func(is+1,ik,s,strk,DP)+1;
//                else return DP[is][ik] = func(is+1,ik+1,s,strk,DP)+1;
//             }
//             else
//             {
//                if(ik == 0) return DP[is][ik] = func(is+1,ik,s,strk,DP)+1;
//                else return DP[is][ik] = max(func(is+1,ik+1,s,strk,DP)+1,func(is+1,ik,s,strk,DP));
//             }
//         }
//         else
//         {
//             if(strk[ik] == '0')
//             {
//                return DP[is][ik] = func(is+1,ik,s,strk,DP);
//             }
//             else
//             {
//                return DP[is][ik] = max(func(is+1,ik+1,s,strk,DP)+1,func(is+1,ik,s,strk,DP));
//             }
//         }
//     }

//     int longestSubsequence(string s, int k) {
//         int n = s.size();

//         string strk;
//         while(k != 0)
//         {
//             strk += (k%2 + '0');
//             k /= 2;
//         }

//         reverse(strk.begin(),strk.end());
//         cout<<s<<" "<<strk<<endl;
//         vector<vector<int>>DP(n+1,vector<int>(strk.size()+1,-1));
//         return func(0,0,s,strk,DP);
//     }
// };

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int count = 0;
        long long value = 0;
        int power = 0;
        
        // Process from right to left (least significant bit first)
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '1') {
                // Check if adding this bit would exceed k
                if(power < 31 && value + (1LL << power) <= k) {
                    value += (1LL << power);
                    count++;
                }
            } else {
                // Always include '0' bits as they don't increase value
                count++;
            }
            power++;
            
            // If power becomes too large, remaining '1' bits can't be included
            if(power >= 31 && value < k) {
                // Count remaining '0' bits
                for(int j = i - 1; j >= 0; j--) {
                    if(s[j] == '0') count++;
                }
                break;
            }
        }
        
        return count;
    }
};