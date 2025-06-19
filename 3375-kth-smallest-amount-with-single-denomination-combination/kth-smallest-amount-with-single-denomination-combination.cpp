class Solution {
public:
    long long func(vector<vector<long long>>&vect, long long val)
    {
        long long cnt = 0;
        for(int i = 1 ; i < vect.size() ; i++ )
        {
            if(i%2 == 1)
            {
                for(int j = 0 ; j < vect[i].size() ; j++ ) cnt += (val/vect[i][j]);
            }
            else
            {
                for(int j = 0 ; j < vect[i].size() ; j++ ) cnt -= (val/vect[i][j]);
            }
        }
        return cnt;
    }

    long long gcd(long long a, long long b) {
    while(b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        for(int i = 0 ; i < n ; i++ )
        {
            if(coins[i] == -1) continue;
            for(int j = (i+1) ; j < n ; j++ )
            {
                if(coins[j]%coins[i] == 0) coins[j] = -1;
            }
        }

        vector<vector<long long>>vect(n+1,vector<long long>(0));
        vect[0].push_back(1);

        for(int i = 0 ; i < n ; i++ )
        {
            if(coins[i] == -1) continue;
            for(int j = (n-1) ; j >= 0 ; j--)
            {
                for(int m = 0 ; m < vect[j].size() ; m++ )
                {
                    vect[j+1].push_back(lcm(vect[j][m],coins[i]));
                }
            }
        }

        long long s = 0, e = 1e18, m;
        while((e-s) > 1)
        {
            m = (s+e)/2;
            if(func(vect,m) >= k)
            {
                e = m;
            }
            else
            {
                s = m;
            }
        }
        if(func(vect,e) <= k) return e;
        else return s;
    }
};