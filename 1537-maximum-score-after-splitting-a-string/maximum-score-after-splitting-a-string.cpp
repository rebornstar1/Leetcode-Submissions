class Solution {
public:
    int maxScore(string s) {
        int N = s.size();
        vector<int>prefix(N+1,0);
        if(s[0] == '0') prefix[0] = 0;
        else prefix[0] = 1;

        for(int i = 1 ; i < N ; i++ )
        {
            prefix[i] += prefix[i-1];
            if(s[i] == '1') prefix[i]++;
        }

        int ans = INT_MIN;
        for(int i = 0 ; i < (N-1) ; i++ )
        {
           ans = max(ans, i+1-prefix[i] + prefix[N-1] - prefix[i]);
           cout<<ans<<endl;
        }
        return ans;
    }
};