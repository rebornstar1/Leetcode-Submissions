class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int s = intervals[0][0], e = intervals[0][1];
        for(int i = 1 ; i < n ; i++ )
        {
            int u = intervals[i][0];
            int v = intervals[i][1];

            if(s <= u && u <= e)
            {
                e = max(e,v);
            }
            else
            {
                ans.push_back({s,e});
                s = u;
                e = v;
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};