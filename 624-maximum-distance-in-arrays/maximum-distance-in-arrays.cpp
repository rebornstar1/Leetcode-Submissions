class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();
        multiset<int>st;
        for(int i = 0 ; i < m ; i++ )
        {
            int u = arrays[i].size();
            st.insert(arrays[i][0]);
            st.insert(arrays[i][u-1]);
        }

        int ans = INT_MIN;
        for(int i = 0 ; i < m ; i++ )
        {
            int u = arrays[i].size();
            auto it = st.find(arrays[i][u-1]);
            st.erase(it);
            auto kp = st.end();
            kp--;
            ans = max(ans,abs(*kp-arrays[i][0]));
            st.insert(arrays[i][u-1]);
        }

        for(int i = 0 ; i < m ; i++ )
        {
            int u = arrays[i].size();
            auto it = st.find(arrays[i][0]);
            st.erase(it);
            auto kp = st.end();
            kp--;
            ans = max(ans,abs(*kp-arrays[i][u-1]));
            st.insert(arrays[i][0]);
        }
        return ans;
    }
};

// Time Complexity is Extremely High for this