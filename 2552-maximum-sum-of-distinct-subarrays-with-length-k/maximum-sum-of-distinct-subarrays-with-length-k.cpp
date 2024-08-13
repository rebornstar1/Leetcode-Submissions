class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp; // To Keep the Count of Numbers in the array
        long long sum = INT_MIN, ind = 0, curr = 0;
        for(int i = 0 ; i < n ; i++ )
        {
            if(mp[nums[i]] == 1)
            {
                int prev = (i-ind);
                while(mp[nums[i]] == 1)
                {
                    mp[nums[prev]]--;
                    ind--;
                    curr -= nums[prev];
                    prev++;
                }
            }

            curr += nums[i];
            ind++;
            mp[nums[i]]++;
            
            if(ind == k)
            {
               sum = max(sum,curr);
               ind--;
               curr -= nums[i-k+1];
               mp[nums[i-k+1]]--;
            }
        }
        return sum != INT_MIN ? sum : 0;
    }
};

// Standard Two Pointer Problem