class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        // First try to find the Minimum length array till ith index
        vector<int>lastk(n+1,n+5);
        vector<int>firstk(n+1,n+5);

        unordered_map<int,int>mp;
        mp[0] = 1;
        mp[arr[0]] = 2;
        for(int i = 1 ; i < n ; i++ )
        {
           arr[i] += arr[i-1];
           mp[arr[i]] = (i+2);
        } 
        
        for(int i = 0 ; i < n ; i++ )
        {
            if(mp[arr[i]-target] != 0)
            {
                lastk[i] = (mp[arr[i]]-mp[arr[i]-target]);
            }
        }

        for(int i = 0 ; i < n ; i++ )
        {
            if(mp[arr[i]+target] != 0)
            {
                firstk[i+1] = (-mp[arr[i]]+mp[arr[i]+target]);
            }
        }

        for(int i = (n-2) ; i >= 0 ; i-- )
        {
            firstk[i] = min(firstk[i],firstk[i+1]);
        }

        for(int i = 1 ; i < n ; i++ )
        {
            lastk[i] = min(lastk[i],lastk[i-1]);
        }

        int ans = INT_MAX;

        for(int i = 0 ; i < (n-1) ; i++ )
        {
             ans = min(ans,lastk[i]+firstk[i+1]);
        }

        if(ans > n) return -1;
        return ans;
    }
};