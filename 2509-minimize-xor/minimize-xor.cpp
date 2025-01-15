class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = 0;
        // count of set bits in num2 is evaluated
        while(num2 != 0){
            cnt += (num2&1);
            num2 = (num2 >> 1);
        }

        cout<<cnt<<endl;
        
        string s;
        while(num1 != 0)
        {
            // cout<<(num1&1 + '0')<<endl;
            s += (num1%2 + '0');
            num1 = (num1 >> 1);
        }

        if(s.size() <= cnt)
        {
            int p = 0;
            while(cnt--)
            {
                p *= 2;
                p++;
            }
            return p;
        }
        else
        {
            cout<<s<<endl;
            for(int i = (s.size()-1) ; i >= 0 ; i-- )
            {
                if(s[i] == '1' && cnt <= 0)
                {
                    s[i] = '0';
                }
                if(s[i] == '1') cnt--;
            }

            for(int i = 0 ; i < s.size() ; i++ )
            {
                if(s[i] == '0' && cnt != 0)
                {
                    s[i] = '1';
                    cnt--;
                }
            }

            cout<<s<<endl;

            int num = 0;
            for(int i = (s.size()-1) ; i >= 0 ; i-- )
            {
                num *= 2;
                num += (s[i]-'0');
            }

            

            return num;
        }
    }
};