class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        unordered_map<int,int>mp;
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(1);
        mp[1]++;
        int cnt = 0;
        long long val = 1;

        while(!pq.empty() && cnt < n)
        {
           long long num = pq.top();
           pq.pop();
           cnt++;
           cout<<num<<" "<<cnt<<endl;
           if(cnt == n ) return num;
           for(int i = 0 ; i < primes.size() ; i++ )
           {
               long long flex = (num*primes[i]);
               if(flex <= INT_MAX && !(pq.size() > n && flex > val))
               {
                   if(mp[num*primes[i]] == 0)
                    {
                        val = max(val,num*primes[i]);
                        pq.push(num*primes[i]);
                        mp[num*primes[i]]++;
                    }   
               }
               else
               {
                  break;
               }
           }
        }
        return 0;
    }
};

// This is also not the most optimal solution