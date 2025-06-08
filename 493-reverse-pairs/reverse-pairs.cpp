class Solution {
private:
    int ans = 0;
public:
    void merge(int l,int m,int r,vector<int>&nums)
    {
        vector<int>left;
        vector<int>right;
        for(int i = l ; i <= m ; i++ )
        {
            left.push_back(nums[i]);
        }
        for(int i = (m+1) ; i <= r ; i++ )
        {
            right.push_back(nums[i]);
        }

        int index = l, alpha = 0, beta = 0;
        
        int flip = 0;
        for (int i = 0; i < left.size(); i++) {
            while (flip < right.size() && (long long)left[i] > 2LL * right[flip]) {
                flip++;
            }
            ans += flip;
        }


        while(alpha < left.size() && beta < right.size()) {

            // find the count here itself
            if(left[alpha] > right[beta]) {
                nums[index++] = right[beta++];
            } else {
                nums[index++] = left[alpha++];
            }
        }

        while(alpha < left.size()) {
            nums[index++] = left[alpha++];
        }

        while(beta < right.size()) {
            nums[index++] = right[beta++];
        }

    }

    void mergeSort(int l,int r,vector<int>&nums)
    {
        if((r-l)<1) return;
        int m = (l+r)/2;
        mergeSort(l,m,nums);
        mergeSort(m+1,r,nums);
        merge(l,m,r,nums);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergeSort(0,n-1,nums);
        return ans;
    }
};

// first write the whole code for the merge sort itself