class Solution {
public:
    long long countProductsLessOrEqual(vector<int>& nums1, vector<int>& nums2, long long target) {
        long long count = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        
        for (int i = 0; i < n1; i++) {
            if (nums1[i] == 0) {
                if (target >= 0) {
                    count += n2;
                }
                continue;
            }
            
            if (nums1[i] > 0) {
                long long maxVal = target / nums1[i];
                int left = 0, right = n2 - 1;
                int pos = -1;
                
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if ((long long)nums2[mid] * nums1[i] <= target) {
                        pos = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                count += (pos + 1);
            } else {
                long long minVal = (target + nums1[i] - 1) / nums1[i];
                int left = 0, right = n2 - 1;
                int pos = n2;
                
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if ((long long)nums2[mid] * nums1[i] <= target) {
                        pos = mid;
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                count += (n2 - pos);
            }
        }
        
        return count;
    }
    
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        long long left = -1e10, right = 1e10;
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (countProductsLessOrEqual(nums1, nums2, mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};