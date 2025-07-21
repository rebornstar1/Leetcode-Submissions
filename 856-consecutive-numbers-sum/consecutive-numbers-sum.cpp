class Solution {
public:
    int consecutiveNumbersSum(int n) {
        // first pre compute for the numbers till 1e5 itself

        int sizze = sqrt(2*n)+1;

        vector<long long>preCompute(sizze,0);
        int ans = 0;
        for(int i = 1 ; i < sizze ; i++ )
        {
            preCompute[i] = (i+preCompute[i-1]);
            if((n-preCompute[i])%i == 0 && n >= preCompute[i]) ans++; 
        }
        return ans;
    }
};

// see if we can optimize this solution 