class Solution {
public:
    int consecutiveNumbersSum(int n) {
        // first pre compute for the numbers till 1e5 itself

        vector<long long>preCompute(1e5+1,0);
        int ans = 0;
        for(int i = 1 ; i < 1e5 ; i++ )
        {
            preCompute[i] = (i+preCompute[i-1]);
            if((n-preCompute[i])%i == 0 && n >= preCompute[i]) ans++; 
        }
        return ans;
    }
};