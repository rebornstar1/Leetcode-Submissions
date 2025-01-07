class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        // Naive Approach O(100*100*30*30)

        // O(30*30*100) Find all possible substrings of all the strings except for that
        // string itself in map and check out if any of the available string has some similar

        unordered_set<string>st;
        for(int i = 0 ; i < words.size() ; i++ ) st.insert(words[i]);

        unordered_map<string,int>mp;
        int n = words.size();
        for(int i = 0 ; i < n ; i++ )
        {
            for(int j = 0 ; j < words[i].size() ; j++ )
            {
                for(int k = 1 ; k <= (words[i].size()-j) ; k++ )
                {
                    if(j == 0 && k == (words[i].size()-j)) continue;
                    mp[words[i].substr(j,k)]++;
                }
            }
        }

        vector<string>ans;
        for(auto it : mp)
        {
            if(st.find(it.first) != st.end())
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};