class Solution {
public:
    bool checksum(int target, vector<int>&nums,int m)
    {
         int sum = 0;
         int ans = 0;
         for(int i = 0 ; i < m ; i++ )
         {
            sum += nums[i];
         }
         ans = max(ans,sum);
         for(int i = m ; i < nums.size() ; i++ ){
            sum+=nums[i];
            sum-=nums[i-m];
            ans = max(ans,sum);
            cout<<sum<<" ";
         }
         //cout<<endl;

         return ans >= target;
    }

    // Let's Check for the first False Condition Now
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int s = 1, e = n , m;
        while((e-s) > 1 )
        {
           m= (s+e)/2;
           cout<<e<<" "<<s<<" "<<m<<endl;
           if(checksum(target,nums,m))
           {
              e = m;
           }
           else
           {
             s = (m+1);
           }
        }
        //cout<<e<<" "<<s<<" "<<m<<endl;
        //cout<<checksum(target,nums,m)<<endl;
        if(checksum(target,nums,s))
        {
           return s;
        }
        else if(checksum(target,nums,e))
        {
           return e;
        }
        else
        {
            return 0;
        }
    }
};