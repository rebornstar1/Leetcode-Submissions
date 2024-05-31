class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
         int n = nums.size();
         int a = 0, b = 0;
         int result = 0;
         for(int i = 0 ; i < nums.size() ; i++ )
         {
             result^=nums[i];
         }
         int val;
         if(result == INT_MIN) val = 1;
         else { val = result&(~(result-1)); }
         cout<<val<<endl;
         for(int i = 0 ; i < nums.size() ; i++ )
         {
            if((val&nums[i]) == 0)
            {
                b^=nums[i];
                cout<<b<<" "<<"b"<<endl;
            }
            else
            {
                a^=nums[i];
                cout<<a<<" "<<"a"<<endl;
            }
         }
         
         return {a,b};
    }
};