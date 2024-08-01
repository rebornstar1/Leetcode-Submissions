class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        int n = details.size();
        int p = details[0].size();
        for(int i = 0 ; i < n ; i++ )
        {
                int val = ((details[i][p-4]-'0')*10+(details[i][p-3]-'0'));
                if(val > 60)
                {
                cnt++;
                }
        }
        return cnt;
    }
};