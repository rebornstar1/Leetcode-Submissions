class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int ind = 0,ans = 0;
        int prev = 0;
        multiset<int>test;
        while(ind != n)
        {
           test.insert(nums[ind]);
           auto it1 = test.begin();
           auto it2 = test.end();
           it2--;
           while(((*it2)-(*it1)) > limit)
           {
             auto it = test.find(nums[prev]);
             test.erase(it);
             it1 = test.begin();
             it2 = test.end();
             prev++;
           }
           int temp = test.size();
           ans = max(ans,temp);
           ind++;
        }
        return ans;
    }
};

// Now Make THIS Solution Optimal and learn some new approaches