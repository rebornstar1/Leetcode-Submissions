class Solution {
public:
    int consecutiveNumbersSum(int n) {
        // first pre compute for the numbers till 1e5 itself

        int sizze = sqrt(2*n)+1;
        int ans = 0;
        int pre = 0;
        for(int i = 1 ; i < sizze ; i++ )
        {
            int curr = (i+pre);
            if((n-curr)%i == 0 && n >= curr) ans++; 
            pre = curr;
        }
        return ans;
    }
};

//  see if we can optimize it more

// see if we can optimize this solution 