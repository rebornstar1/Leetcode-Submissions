class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // The Bruteforce Approach => each time sort and considering the last element and 
        // adding it's square into this
        // It's Time Complexity is around O(N*log(N)*K)

        // size of the gifts
        int n = gifts.size();
        while(k--)
        {
            sort(gifts.begin(),gifts.end());
            gifts[n-1] = sqrt(gifts[n-1]);
        }

        long long sum = 0;
        for(int i = 0 ; i < n ; i++ )
        {
            sum += gifts[i];
        }
        return sum;
    }
};