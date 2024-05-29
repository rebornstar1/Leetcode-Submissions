class Solution {
public:
    int numSteps(string s) {
        int flag = 0;
        int ans = 0;
        for(int i = (s.size()-1) ; i > 0 ; i-- )
        {
            if(s[i] == '0')
            {
               if(flag == 1)
               {
                 ans+=2;
                 flag = 1;
               }
               else
               {
                 ans++;
                 flag = 0;
               }
            }
            else
            {
               if(flag == 1)
               {
                 ans++;
                 flag = 1;
               }
               else
               {
                ans += 2;
                flag = 1;
               }
            }
        }
        if(flag == 1)
        {
            ans++;
        }
        return ans;
    }
};