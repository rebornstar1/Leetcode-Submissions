class Solution {
private:
    vector<int>preCompute;
public:
    void flagCompute(int a)
    {
        preCompute.push_back(1);
        int ind = 1, val = 1;
        while(ind != 10)
        {
           val = (val*a)%1337;
           preCompute.push_back(val);
           ind++;
        }
    }

    int cntSimp(int a,int n)
    {
        int val = 1;
        while(n--)
        {
            val = (val*a)%1337;
        }
        return val;
    }

    int func(int a,vector<int>& b,int ind)
    {
        if(ind < 0) return 1;

        if(b[ind]%2 == 0)
        {
           int temp = preCompute[b[ind]/2]%1337;
           return (((temp*temp)%1337)*(cntSimp(func(a,b,ind-1),10)%1337))%1337;
        }
        else
        {
           int temp = preCompute[b[ind]/2]%1337;
           return (((temp*temp)%1337)*((a*cntSimp(func(a,b,ind-1),10))%1337))%1337;
        }
    }

    int superPow(int a, vector<int>& b) {
        int n = b.size();
        flagCompute(a%1337);
        int val = (func(a%1337,b,n-1))%1337;
        return val;
    }

    // Check If this can be more optimised
};