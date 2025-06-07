class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        unordered_map<int,int>mp;
        mp[0] = 1;
        mp[arr[0]] = 2;
        for(int i = 1 ; i < n ; i++ )
        {
           arr[i] += arr[i-1];
           mp[arr[i]] = (i+2);
        } 
        
        int temp = (n+5), ans = INT_MAX; // impossible value
        for(int i = 0 ; i < n ; i++ )
        {
            if(i > 0 && mp.find(arr[i-1]+target) != mp.end() && mp[arr[i-1]+target] != 0)
            {
                ans = min(ans,temp+mp[arr[i-1]+target]-1-i);
            }

            // and now update the ending one here
            if(mp.find(arr[i]-target) != mp.end() && mp[arr[i]-target] != 0)
            {
                temp = min(temp,mp[arr[i]]-mp[arr[i]-target]);
            }
        }

        if(ans > n) return -1;
        return ans;
    }
};

// Think if you can optimize this solution further