class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        map<int,int>mp;
        int val = INT_MIN;
        for(int i = 0 ; i < n ; i++ )
        {
            mp[nums[i]]++;
            val = max(val,nums[i]);
        }

        int temp = 0, ans = 1;
        for(auto it : mp)
        {
            if((it.first - val) != 1)
            {
                ans = max(ans,temp);   
                temp = 1;
            }
            else
            {
                temp++;
                ans = max(ans,temp);
            }
            val = it.first;
        }

        return ans;
    }
};
