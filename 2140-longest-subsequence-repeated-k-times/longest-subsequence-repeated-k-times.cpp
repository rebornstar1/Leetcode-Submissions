class Solution {
public:
    bool func(string &curr_str, string &s,int k)
    {
        int m = curr_str.size(), n = s.size();
        int temp = 0;
        for(int i = 0 ; i < n ; i++ )
        {
            if(s[i] == curr_str[temp%m])
            {
               temp++;
            }
        }

        return temp >= (m*k);
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        vector<int>freq(26,0);
        for(int i = 0 ; i < n ; i++ ) freq[s[i]-'a']++;

        vector<char>next_char;

        queue<string>qst;
        for(int i = 25 ; i >= 0 ; i-- )
        {
           if(freq[i] >= k) 
           {
              string temp;
              temp += (i+'a');
              qst.push(temp);
              next_char.push_back((char)('a'+i));
           }
        }
        string ans;

        while(!qst.empty())
        {
            string curr_str = qst.front();
            if(curr_str.size() > ans.size() || (curr_str.size() == ans.size() && curr_str > ans)) ans = curr_str;
            qst.pop();
            for(int  i = 0 ; i < next_char.size() ; i++ )
            {
                string temp_str = curr_str;
                temp_str += next_char[i];
                if(func(temp_str,s,k))
                {
                   qst.push(temp_str);
                }
            }
        }

        return ans;
    }
};