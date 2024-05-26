class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<long long,long long>mp;
        for(int i = 0 ; i < nums2.size() ; i++)
        {
            mp[nums2[i]*k]++;
        }
        long long houp = 0;
        unordered_map<long long,long long>tp;
        for(int i = 0 ; i < nums1.size() ; i++ )
        {
           for (int j=1; j*j <= nums1[i]; j++) 
            { 
                if (nums1[i]%j == 0) 
                { 
                    if (nums1[i]/j == j) 
                    {
                       tp[j]++;
                    }
                    else{
                        tp[j]++;
                        tp[nums1[i]/j]++;
                    }
                } 
            } 
        }

        for(auto it : tp)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }


        long long sum = 0;
        for(int i = 0 ; i < nums2.size() ; i++ )
        {
            sum += tp[nums2[i]*k];
        }
        return sum;
    }
};