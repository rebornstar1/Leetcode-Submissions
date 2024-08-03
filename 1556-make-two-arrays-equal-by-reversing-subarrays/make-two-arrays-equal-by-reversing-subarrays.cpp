class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>mp;
        int n = target.size();
        for(int i = 0 ; i < n ; i++ )
        {
            mp[target[i]]++;
            mp[arr[i]]--;
        }

        for(auto it : mp)
        {
            if(it.second != 0) return false;
        }
        return true;
    }
};

// This is O(NlogN) Aprroach