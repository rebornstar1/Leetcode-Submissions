class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        for(int i = 1 ; i < n ; i++ )
        {
          // Prefix XOR of the whole array
          arr[i] = (arr[i]^arr[i-1]);
        }
        
        int cnt = 0;
        for(int i = 0 ; i < (n-1) ; i++ )
        {
            for(int j = (i+1) ; j < n ; j++ )
            {
                for(int k = j ; k < n ; k++ )
                {
                    // This will be the O(N*N*N) Time Complexity Function
                    if( i == 0)
                    {
                        if(arr[k] == 0)
                        {
                            cnt++;
                        }
                    } 
                    else
                    {
                        if(arr[k] == arr[i-1])
                        {
                            cnt++;
                        }
                    }
                    // if(arr[k] == (i>0)?arr[i-1]:0)
                    // {
                    //     cnt++;
                    // }
                }
            }
        }
        return cnt;
    }
};