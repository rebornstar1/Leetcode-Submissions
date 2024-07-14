class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        int flag = 0;
        for(int i = 0 ; i < n ; i++ )
        {
            for(int j = i ; j > 0 ; j-- )
            {
                int num = (s[j]-'0');
                int val = (s[j-1]-'0');
                if((num%2 == val%2) && (num < val))
                {
                    swap(s[j],s[j-1]);
                    flag = 1;
                    break;
                }
                else
                {
                    break;
                }
            }
            if(flag == 1) break;
        }
        return s;
    }
};