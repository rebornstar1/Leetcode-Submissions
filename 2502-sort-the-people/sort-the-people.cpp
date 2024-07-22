class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        map<int,string>mp;
        for(int i = 0 ; i < n ; i++ )
        {
            mp[heights[i]] = names[i];
        }

        //names.clear();
        int flip = (n-1);
        for(auto it : mp)
        {
            names[flip] = it.second;
            flip--;
        }
        return names;
    }
};