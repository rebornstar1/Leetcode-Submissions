class Solution {
public:
    int func(vector<int>&nums,int m)
    {
        int cnt = 0 ;
        for(int i = 0 ; i < nums.size() ; i++ )
        {
            if(nums[i] >= m )
            {
                cnt++;
            }
        }
        return cnt;
    }

    int specialArray(vector<int>& nums) {
        // Binary Search for the Optimal Solution 
        int s = 0, e = 1000, m ;
        while(s <= e)
        {
            m = (s+e)/2;
            if(func(nums,m) > m)
            {
               s = m+1;
            }
            else if(func(nums,m) == m)
            {
                return m;
            }
            else
            {
              e = m-1;
            }
        }
        cout<<s<<" "<<m<<" "<<e<<endl;
        return -1;
    }
};