class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int>st;
        st.insert(nums[0]);
        for(int i = 1 ; i < nums.size() ; i++ )
        {
          auto it = st.end();
          it--;
          if(nums[i] > (*it))
          {
             st.insert(nums[i]);
          }
          else
          {
            auto kp = st.lower_bound(nums[i]);
            if(kp != st.end())
            {
                st.erase(kp);
                st.insert(nums[i]);
            }
          }
        }
        return st.size();
    }
};

// Write an Algorithm which runs in NlogN Time Complexity 