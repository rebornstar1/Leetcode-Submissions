class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int,int>>st;
        st.push({0,temperatures[0]});
        vector<int>ans(n,0);
        for(int i = 1 ; i < n ; i++ )
        {
            while(!st.empty() && temperatures[i] > st.top().second)
            {
                ans[st.top().first] = (i-st.top().first);
                st.pop();
            }
            st.push({i,temperatures[i]});
        }
        return ans;
    }
};