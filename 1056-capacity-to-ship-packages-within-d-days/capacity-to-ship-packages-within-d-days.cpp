class Solution {
public:
    bool checkfunc(vector<int>& weights, int days, int m)
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

        return cnt <= days;
    }

    // we are gonna put them in order

    int shipWithinDays(vector<int>& weights, int days) {
        int s = 1 , e = 1e9 , m;
        while((e-s)>1)
        {
            m = (s+e)/2;
            if(checkfunc(weights,days,m))
            {
                e = m;
            }
            else
            {
                s = (m+1);
            }
        }

        if(checkfunc(weights,days,s))
        {
            return s;
        }
        else
        {
            return e;
        }
    }
};