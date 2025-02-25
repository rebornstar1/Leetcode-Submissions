class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int M = 1000000007;
        int even = 0, odd = 0;
        int ans = 0;
        for(int i = 0 ; i < n ; i++ )
        {
            if(arr[i]%2 == 0)
            {
               // If the number is even
               even++;
            }
            else
            {
              // If the number is odd 
              swap(odd,even);
              odd++;
            }
            ans  = (ans + odd)%M;
        }
        return ans%M;
    }
};