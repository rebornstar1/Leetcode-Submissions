class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int num = edges.size();
        vector<int> temp[num+2];
       // vector<vector<int>>temp(num+1);
        for(int i = 0 ; i < edges.size() ; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            temp[u].push_back(v);
            temp[v].push_back(u);
        }

        for(int i = 0 ; i <= (num+1) ; i++ )
        {
            if(temp[i].size() == num)
            {
                return (i);
            }
        }
        return -1;
    }
};