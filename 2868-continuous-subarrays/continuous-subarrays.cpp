class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // It Seems Like a standard Two Pointer Question
        int n = nums.size();
        int prev = 0, curr = 0;
        multiset<int>st;
        st.insert(nums[0]);
        long long ans = 1;
        unordered_map<int,int>mp;
        mp[0]++;
        while(curr != n)
        {
            auto it1 = st.end(), it2 = st.begin();
            it1--;
            if(abs(*it1-*it2) > 2)
            {
               auto tempRemove = st.find(nums[prev]);
               st.erase(tempRemove);
               prev++;
            }
            else
            {
                int compSize = st.size();
                if(mp[curr] == 0)
                {
               // cout<<compSize<<" "<<prev<<" "<<curr<<endl;
                ans += compSize;
                } 
                mp[curr]++;

                curr++;
                if(curr == n) break;
                st.insert(nums[curr]);
            }

            
        }
        return ans;
    }
};