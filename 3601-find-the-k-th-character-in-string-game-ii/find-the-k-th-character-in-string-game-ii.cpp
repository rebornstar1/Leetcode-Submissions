class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
       int n = operations.size();
       map<long long,long long>mp;
       long long twoPow = 1, index = 0;

       while(twoPow < k)
       {
          mp[twoPow] += (index < n ? operations[index] : 0);
          twoPow *= 2;
          index++;
       }
       long long tempVal = k, currentVal = 0;
       while(tempVal > 1)
       {
          auto it = mp.lower_bound(tempVal);
          it--;
          long long num1 = (*it).first;
          long long num2 = (*it).second;

          tempVal -= num1;
          currentVal -= num2;
       }

       return ('a'+(-currentVal)%26);
    }
};