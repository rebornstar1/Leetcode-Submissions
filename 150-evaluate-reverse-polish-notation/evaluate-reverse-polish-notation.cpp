class Solution {
public:
    bool isOp(string &ch)
    {
        return ((ch == "+") || (ch == "-") || (ch == "*") || (ch == "/"));
    }

    int stoi(string &s){

        int val = 0;
        if(s[0] == '-') val = 1;

        int num = 0;
        for(int i = val ; i < s.size() ; i++ )
        {
            num *= 10;
            num += (s[i]-'0');
        }

        if(val) return -1*num;
        return num;
    }

    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;
        for(int i = 0 ; i < n ; i++ )
        {
            if(isOp(tokens[i]))
            {
               int num1 = st.top();
               st.pop();
               int num2 = st.top();
               st.pop();
               swap(num1,num2);
               if(tokens[i] == "+")
               {
                  st.push(num1+num2);
               }
               else if(tokens[i] == "-")
               {
                  st.push(num1-num2);
               }
               else if(tokens[i] == "*")
               {
                  st.push(num1*num2);
               }
               else
               {
                  st.push(num1/num2);
               }
            }
            else
            {
               st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};