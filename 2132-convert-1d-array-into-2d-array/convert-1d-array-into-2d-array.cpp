class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {

        if(original.size() != m*n) return {};

        vector<vector<int>>ans;
        for(int i = 0 ; i < original.size() ; i += n)
        {
            vector<int>temp;
            for(int j = i ; j < (i+n) ; j++ )
            {
               temp.push_back(original[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};