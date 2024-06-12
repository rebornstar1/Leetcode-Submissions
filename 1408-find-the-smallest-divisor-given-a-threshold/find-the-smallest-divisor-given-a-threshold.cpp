class Solution {
public:
    bool checkfunc(vector<int>& nums,int threshold,int m)
    {
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++ )
        {
            if(nums[i]%m == 0)
            {
                sum += (nums[i]/m);
            }
            else
            {
                sum += (nums[i]/m +1 );
            }
        }
        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
       int s = 1 , e = 1e9 , m;
       while((e-s) > 1)
       {
          m = (s+e)/2;
          if(checkfunc(nums,threshold,m))
          {
              e = m;
          }
          else
          {
            s = (m+1);
          }
       }  

       if(checkfunc(nums,threshold,s))
       {
          return s;
       }
       else
       {
          return e;
       }
    }
};