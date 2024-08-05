class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mp;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++ )
        {
            mp[arr[i]]++;
        }

        int ind = 0;
        for(int i = 0 ; i < n ; i++ )
        {
            mp[arr[i]]--;
            if(mp[arr[i]] == 0)
            {
                cout<<arr[i]<<endl;
                ind++;
                if(ind == k)  return arr[i];
            }
            mp[arr[i]]++;
        }

        return "";
    }
};