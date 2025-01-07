class Solution {
public:
    long long calculateScore(string s) {
        long long score = 0;
        int n = s.size();
        vector<vector<long long>>inc(30);

        for(int i = 0 ; i < n ; i++ )
        {
            if(!inc['z'-s[i]].empty())
            {
                long long index = inc['z'-s[i]].back();
                inc['z'-s[i]].pop_back();
                score += abs(index-i);
            } 
            else
            {
                inc[s[i]-'a'].push_back(i);
            }
        }
        return score;
    }
};