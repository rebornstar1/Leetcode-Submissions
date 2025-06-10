class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i = 0 ; i < n ; i++ ) sum += nums[i];
        if(sum%2 == 1) return false;
        vector<int>prev(sum/2+1,0);
        vector<int>curr(sum/2+1,0);

        for(int i = 0 ; i <= n ; i++ ) prev[0] = 1;

        for(int i = (n-1) ; i >= 0 ; i-- )
        {
            for(int j = 0 ; j <= (sum/2) ; j++ )
            {
                int val1 = ((j-nums[i]) >= 0 ? prev[j-nums[i]] : 0);
                int val2 = prev[j];
                curr[j] = (val1 | val2); 
                if(curr[sum/2]) return true;
            }
            prev = curr;
        }
        return curr[sum/2];
    }
};

// I want to Optimize this solution More