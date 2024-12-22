class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> nge(n, -1);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] <= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }
            st.push(i);
        }
        
        vector<int> ans;
        for (auto& query : queries) {
            sort(query.begin(), query.end());
            int left = query[0], right = query[1];
            int index = left;
            
            if (right == nge[left] || heights[right] > heights[left] || right == left) {
                ans.push_back(right);
            } else if (nge[left] == -1 || nge[right] == -1) {
                ans.push_back(-1);
            } else {
                int ind = max(nge[left], nge[right]);
                if (heights[ind] > heights[left] && heights[ind] > heights[right]) {
                    ans.push_back(ind);
                } else {
                    while (ind != -1 && (heights[ind] < heights[left] || heights[ind] < heights[right])) {
                        ind = nge[ind];
                    }
                    if (ind != -1 && heights[ind] > heights[left] && heights[ind] > heights[right]) {
                        ans.push_back(ind);
                    } else {
                        ans.push_back(-1);
                    }
                }
            }
        }
        return ans;
    }
};