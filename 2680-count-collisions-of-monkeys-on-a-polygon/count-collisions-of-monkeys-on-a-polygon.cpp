class Solution {
private:
    int M = 1000000007;
public:
    // Use This Function Just to Count the Powers of 2 Respectively
    int func(int n)
    {
        if(n == 0) return 1;

        if(n%2 == 0)
        {
            long long val = func(n/2)%M;
            return (val*val)%M;
        }
        else
        {
            long long val = func(n/2)%M;
            return (val*((val*2)%M))%M;
        }
    }

    int monkeyMove(int n) {
        return (func(n)-2+M)%M;
    }
};

// Here The Answer is 2^n-2 Respectively