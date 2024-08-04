class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int>st;
        vector<int>ans;
        for(int i = 0 ; i < (n-1) ; i++ )
        {
            st.insert(i);
        }

        for(int i = 0 ; i < queries.size() ; i++ )
        {
            auto lb = st.lower_bound(queries[i][0]+1);
            auto rb = st.lower_bound(queries[i][1]);

            st.erase(lb,rb);

            ans.push_back(st.size());
        }

        return ans;
    }
};