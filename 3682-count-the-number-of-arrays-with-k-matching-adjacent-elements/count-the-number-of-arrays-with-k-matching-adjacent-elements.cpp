class Solution {
private:
    int M = 1000000007;
    unordered_map<int,int>mp;
public:
    int func(int num,int power)
    {
        if(power == 0) return 1;

        if(mp.find(power) != mp.end() && mp[power]) return mp[power];

        if(power%2 == 0)
        {
            long long temp = func(num,power/2)%M;
            return mp[power] = (temp*temp)%M;
        }
        else
        {
            long long temp = func(num,power/2)%M;
            long long val = (temp*num)%M;
            return mp[power] = (temp*val)%M; 
        }
    }

    int countGoodArrays(int n, int m, int k) {
        long long val1 = 1, temp1 = (n-k-1);
        while(temp1--) val1 = (val1*(m-1))%M;

        long long val2 = 1;
        for(int i = 1 ; i <= (n-1) ; i++ ) val2 = (val2*i)%M;

        long long val3 = 1;
        for(int i = 1 ; i <= (n-1-k) ; i++ ) val3 = (val3*i)%M;

        long long val4 = 1;
        for(int i = 1 ; i <= k ; i++ ) val4 = (val4*i)%M;

        long long val5 = (val3*val4)%M;
        val5 = func(val5,M-2);

        return ((((m%M)*(val1%M))%M)*(((val2%M)*(val5%M))%M))%M;
    }
};