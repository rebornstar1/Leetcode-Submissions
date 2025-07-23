class Solution {
public:

    int maximumGain(string s, int x, int y) {
        int n = s.size();
        stack<char>st;
        bool pref = false;
        if(x >= y) pref = true;
        int ans = 0;
        for(int i = 0 ; i < n ; i++ )
        {
            if(st.empty())
            {
                st.push(s[i]);
                continue;
            }
            
            if(pref)
            {
                if(s[i] == 'b' && st.top() == 'a')
                {
                    st.pop();
                    ans += x;
                }
                else st.push(s[i]);
            }
            else
            {
                if(s[i] == 'a' && st.top() == 'b')
                {
                    st.pop();
                    ans += y;
                }
                else st.push(s[i]);
            }
        }

        // while doing this keep the count of the continuos of b or a's that will help
        int conA = 0, conB = 0;

        while(!st.empty())
        {
            // use the previous status
            if(st.top() == 'a' && conB)
            {
                ans += x;
                conB--;
                st.pop();
                continue;
            }
            else if(st.top() == 'b' && conA)
            {
                ans += y;
                conA--;
                st.pop();
                continue;
            }

            if(st.top() == 'a')
            {
                conA++;
                conB = 0;
            }
            else if(st.top() == 'b')
            {
                conA = 0;
                conB++;
            }
            else 
            {
                conA = 0;
                conB = 0;
            }
            st.pop();
        }
        return ans;
    }
};