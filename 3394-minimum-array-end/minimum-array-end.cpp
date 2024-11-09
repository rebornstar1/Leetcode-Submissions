class Solution {
public:
    long long minEnd(int n, int x) {
        vector<int>num_vect(64,0);
        for(int i = 63 ; i >= 0 ; i-- )
        {
            num_vect[i] = (x%2);
            x /= 2;
        }
 
        vector<int>temp_vect(64,0);
        n--;
        for(int i = 63 ; i >= 0 ; i-- )
        {
            temp_vect[i] = (n%2);
            n /= 2;
        }

        int it = 63;
        for(int i = 63 ; i >= 0 ; i-- )
        {
            if(num_vect[i] == 0)
            {
                num_vect[i] = temp_vect[it];
                it--;
            }
        }

        long long ans_count = 0;
        for(int i = 0 ; i < 64 ; i++ )
        {
            ans_count *= 2;
            ans_count += num_vect[i];
        }
        return ans_count;
    }
};