class Solution {
public:
    int specialArray(vector<int>& nums) {
        map<int,int>mp;
        for(int i = 0 ; i <= 1000 ; i++ )
        {
            mp[i] = 0;
        }

        for(int i = 0 ; i < nums.size() ; i++ )
        {
            mp[nums[i]]++;
        }
        for(int i = 999 ; i >= 0 ; i-- )
        {
            mp[i]+=mp[i+1];
            if(mp[i] == i)
            {
                return i;
            }
        }
        return -1;
    }
};