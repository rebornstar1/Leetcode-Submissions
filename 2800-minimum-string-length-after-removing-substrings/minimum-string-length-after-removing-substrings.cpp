class Solution {
public:
    int minLength(string s) {
        // This Question Needs to be done using Stack
        int n = s.size();
        stack<char>st;
        for(int i = 0 ; i < n ; i++ )
        {
            if(st.size() == 0)
            {
               st.push(s[i]);
               continue;
            }   

            if(st.top() == 'A')
            {
                if(s[i] == 'B')
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
            else if(st.top() == 'C')
            {
                if(s[i] == 'D')
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        return st.size();
    }
};