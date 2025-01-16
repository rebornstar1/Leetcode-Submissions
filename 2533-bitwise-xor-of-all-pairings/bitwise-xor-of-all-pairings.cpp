class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if((n%2 == 0) && (m%2 == 0))
        {
            return 0;
        }
        else
        {
            int ans = 0;
            if(n%2 == 0)
            {
               for(int i = 0 ; i < n ; i++) ans ^= nums1[i];
            }
            else if(m%2 == 0)
            {
               for(int i = 0 ; i < m ; i++) ans ^= nums2[i];
            }
            else
            {
               for(int i = 0 ; i < n ; i++) ans ^= nums1[i];
               for(int i = 0 ; i < m ; i++) ans ^= nums2[i];
            }
            return ans;
        }
        return 0;
    }
};