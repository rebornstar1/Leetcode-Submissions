class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size(); // The Number of Candidates
        
        vector<vector<int>>vect(n+1,vector<int>(32,0));
        for(int i = 0 ; i < n ; i++ )
        {
            int temp = candidates[i];
            for(int j = 31 ; j >= 0 ; j-- )
            {
               vect[i][j] = (temp%2);
               temp /= 2;
               if(temp == 0) break;
            }
        }
        
        int ans_count = 0;
        for(int i = 0 ; i < 32 ; i++ )
        {
            int one_count = 0;
            for(int j = 0 ; j < n ; j++ )
            {
                if(vect[j][i] == 1)
                {
                    one_count++;
                }
                ans_count = max(ans_count,one_count);
            }
        }
        return ans_count;
    }
};