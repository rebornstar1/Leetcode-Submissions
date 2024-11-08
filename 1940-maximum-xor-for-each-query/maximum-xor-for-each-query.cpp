class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
       vector<int>ans;
       int val = 0, n = nums.size();
       for(int i = 0 ; i < n ; i++ )
       {
          val ^= nums[i];
       }   

       int max_num = 0;
       while(maximumBit--)
       {
          max_num = (max_num<<1);
          max_num++;
       }
       
       for(int i = (n-1) ; i >= 0 ; i-- )
       {
          ans.push_back(val^max_num);
          val ^= nums[i];
       }
       return ans;
    }
};