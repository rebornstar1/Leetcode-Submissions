class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long>prefix,order;
        prefix.push_back(0);
        int ind = 0;
        for(int i = 0 ; i < nums.size() ; i++ )
        {
            prefix.push_back(nums[i]+prefix[ind]);
            ind++;
        }

        for(int i = 1 ; i <= n ; i++ )
        {
            for(int j = i ; j <= n ; j++)
            {
                order.push_back(prefix[j]-prefix[i-1]);
            }
        }

        sort(order.begin(),order.end());
        long long ans = 0;
        for(int i = 0 ; i < order.size() ; i++ )
        {
            if(i>=(left-1) && i<=(right-1))
            {
                ans = (ans+order[i])%1000000007;
            }
            else if(i > (right-1))
            {
                break;
            }
        }
        return ans;
    }
};

// This O(N^2 + N^2*log(N^2))