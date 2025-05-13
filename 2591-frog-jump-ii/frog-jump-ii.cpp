class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n  = stones.size();
        int a = 0, b = 0, val = INT_MIN;
        for(int i = 1 ; i < n ; i++ )
        {
            if(a >= b)
            {
                int prevb = b;
                b = stones[i];
                val = max(val,b-prevb);
            }
            else
            {
                int preva = a;
                a = stones[i];
                val = max(val,a-preva);
            }
        }
        return max({val,stones[n-1]-a,stones[n-1]-b});
    }
};