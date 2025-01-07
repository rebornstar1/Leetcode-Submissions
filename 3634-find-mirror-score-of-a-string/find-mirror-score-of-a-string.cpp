class Solution {
public:
    long long calculateScore(string s) {
        long long score = 0;
        int n = s.size();
        vector<priority_queue<long long>>inc(30);

        for(int i = 0 ; i < n ; i++ )
        {
            if(!inc['z'-s[i]].empty())
            {
                long long index = inc['z'-s[i]].top();
                inc['z'-s[i]].pop();
                score += abs(index-i);
            } 
            else
            {
                inc[s[i]-'a'].push(i);
            }
        }
        return score;
    }
};