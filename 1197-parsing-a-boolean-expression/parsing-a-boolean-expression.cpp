class Solution {
public:
    bool cntVal(string &s,int i,vector<int>&dp)
    {
        if(s[i+1] == ')' || s[i+1] == ',')
        {
            if(s[i] == 'f') return false;
            return true;
        }

        if(dp[i] != 0)
        {
            if(dp[i] == 1) return false;
            return true;
        }

        bool topi;

        if(s[i] == '&')
        {
            int temp = (i+2);
            bool ans = true;
            int flag = 1;
            int k = (i+2);
            while(flag != 0)
            {
                 if(s[k] == ',' && flag == 1)
                {
                   cout<<temp<<" "<<k-1<< " "<<ans<<endl;
                   ans &= cntVal(s,temp,dp);
                   temp = (k+1);
                }
                else if(s[k] == '(')
                {
                    flag++;
                }
                else if(s[k] == ')')
                {
                    flag--;
                    if(flag == 0)
                    {
                        cout<<temp<<" "<<k-1<< " "<<ans<<endl;
                        ans &= cntVal(s,temp,dp);
                    }
                }
                k++;
            }
            topi = ans;
            cout<<topi<<endl;
        }
        else if(s[i] == '|')
        {
            int temp = (i+2);
            bool ans = false;
            int flag = 1;
            int k = (i+2);
            while(flag != 0)
            {
                if(s[k] == ',' && flag == 1)
                {
                   cout<<temp<<" "<<k-1<<endl;
                   ans |= cntVal(s,temp,dp);
                   temp = (k+1);
                }
                else if(s[k] == '(')
                {
                    flag++;
                }
                else if(s[k] == ')')
                {
                    flag--;
                    if(flag == 0)
                    {
                        ans |= cntVal(s,temp,dp);
                    }
                }
                k++;
            }
            topi =  ans;
        }
        else if(s[i] == '!')
        {
           topi =  !cntVal(s,i+2,dp);
        }
        if(topi == true)
        {
            dp[i] = 2;
            return true;
        }
        else
        {
            dp[i] = 1;
            return false;
        }
    }

    // Instead of J maintain the variable itself and cnt it's completion

    bool parseBoolExpr(string expression) {
        int n = expression.size();
 
        // Now Apply DP on this question
        vector<int>dp(n+1,0);
        return cntVal(expression,0,dp);
    }
};