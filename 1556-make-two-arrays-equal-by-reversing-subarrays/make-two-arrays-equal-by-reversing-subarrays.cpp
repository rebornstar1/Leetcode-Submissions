class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int>mp(1001, 0);
        int n = target.size();
        for(int i = 0 ; i < n ; i++ )
        {
            mp[target[i]]++;
            mp[arr[i]]--;
        }

        for(auto it : mp)
        {
            if(it != 0) return false;
        }
        return true;
    }
};