class Solution {
public:
    int nthUglyNumber(int n) {
     int cnt = 1;
     map<long long,long long>mp;
     mp[1] = 1;
     for(auto it : mp)
     {
        mp[it.first*2]++;
        mp[it.first*3]++;
        mp[it.first*5]++;
        cnt++;
        if(cnt > n) return it.first;
     }
     return cnt;
    }
};