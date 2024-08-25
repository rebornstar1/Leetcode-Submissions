class Solution {
public:
    double func(double x,int n)
    {
        if(n == 0) return 1.0;
        if(n%2 == 0)
        {
            double val = myPow(x,n/2);
            return val*val;
        }
        else
        {
            double val = myPow(x,n/2);
            return val*val*x;
        }
    }

    double myPow(double x, int n) {
        double ansVal = func(x,abs(n));
        if(n < 0)
        {
            return 1/ansVal;
        }
        return ansVal;
    }
};

// First I'll be Considering Case Where no negative power is out there