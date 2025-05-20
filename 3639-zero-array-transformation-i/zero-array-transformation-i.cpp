class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>calc(1e5+5,0);
        int q = queries.size();
        for(int i = 0 ; i < q ; i++ )
        {
            int u = queries[i][0];
            int v = queries[i][1];

            calc[u]--;
            calc[v+1]++;
        }

        for(int i = 1 ; i < calc.size() ; i++ )
        {
            calc[i] += calc[i-1];
        }

        bool temp = true;
        for(int i = 0 ; i < nums.size() ; i++ )
        {
            nums[i] += calc[i];
            if(nums[i] > 0) temp = false;
        }
        return temp;
    }
};