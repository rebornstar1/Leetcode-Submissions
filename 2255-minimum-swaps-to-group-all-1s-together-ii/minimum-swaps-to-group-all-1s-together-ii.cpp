class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for(int i = 0 ; i < n ; i++ )
        {
            if(nums[i] == 1) cnt++;
            nums.push_back(nums[i]);
        }

        int ans = INT_MAX,curr = 0, prev = 0,temp = 0;
        if(nums[0] ==  1) temp++;

        if(cnt == 0 ) return 0;

        while(prev != n && curr != (2*n))
        {
            if((curr-prev+1) == cnt)
            {
                ans = min(ans,curr-prev-temp+1);
                if(nums[prev] == 1 ) temp--;
                prev++;
            }
            else
            {
                curr++;
                if(nums[curr] == 1) temp++;
            }
        }

        return ans == INT_MAX ?  0 : ans;
    }
};