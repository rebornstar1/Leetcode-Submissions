class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mp;
        int val = 0;
        int ans = 0;
        mp[0] = 1;
        for(int i = 0 ; i < nums.size() ; i++ )
        {
            val += nums[i];
            int jump = (val%k);
            if(val < 0 ) jump+=k;
            if(mp[jump%k] != 0)
            {
              ans += mp[jump%k];
              mp[jump%k]++;
            }
            else
            {
                mp[jump%k]++;
            }
        }
        cout<<(-5)%5<<endl;
        return ans;
    }
};