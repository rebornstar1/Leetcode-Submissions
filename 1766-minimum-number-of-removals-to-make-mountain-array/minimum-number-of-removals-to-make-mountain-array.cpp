class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int>forward(n+1,1);
        vector<int>backward(n+1,1);

        for(int i = 0 ; i < n ; i++ )
        {
            for(int j = (i+1) ; j < n ; j++ )
            {
               if(nums[j] > nums[i])
               {
                  forward[j] = max(forward[j],forward[i]+1);
               }
            }
        }

        // count the same way in backward direction

        for(int i = (n-1) ; i >= 0 ; i-- )
        {
            for(int j = (i-1) ; j >= 0 ; j-- )
            {
               if(nums[j] > nums[i])
               {
                  backward[j] = max(backward[j],backward[i]+1);
               }
            }
        }


        for(int i = 0 ; i < n ; i++ ) cout<<forward[i]<<" ";
        cout<<endl;
        for(int i = 0 ; i < n ; i++ ) cout<<backward[i]<<" ";

        int s = 0, e = n-1;
        // Now Fix these indexes accordingly
        for(int i = 0 ; i < (n-1) ; i++ )
        {
            if(nums[i] >= nums[i+1])
            {
                s++;
            }
            else
            {
                break;
            }
        }

        for(int i = (n-1) ; i > 0 ; i-- )
        {
            if(nums[i] >= nums[i-1])
            {
                e--;
            }
            else
            {
                break;
            }
        }

        int ans = 1;
        for(int i = s ; i <= e ; i++ )
        {
            ans = max(ans,forward[i]+backward[i]-1);
        }
        return n-ans;
    }
};

// Try Iterative Approach for LIS from both the sides