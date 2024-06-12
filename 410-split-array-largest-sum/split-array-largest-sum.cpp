class Solution {
public:
    bool checkfunc(vector<int>& weights, int k, int m)
    {
        // Write the Predcate Function Properly
        int sum = 0;
        int cnt = 1;
        for(int i = 0 ; i < weights.size() ; i++ )
        {
            if(weights[i] > m) return false;
            sum += weights[i];
            if(sum > m)
            {
              sum = weights[i];
              cnt++;
            }
        }

        return cnt <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int s = 0, e = 1e9 , m;
        while((e-s)>1)
        {
            m = (s+e)/2;
            if(checkfunc(nums,k,m))
            {
                e = m;
            }
            else
            {
                s = (m+1);
            }
        }

        if(checkfunc(nums,k,s))
        {
            return s;
        }
        else
        {
            return e;
        }
    }
};