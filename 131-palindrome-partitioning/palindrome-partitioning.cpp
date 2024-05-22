class Solution {
public:
    bool checkPalindrome(string s)
    {
        int n = s.size();
        for(int i = 0 ; i < n ; i++ )
        {
            if(s[i]!=s[n-i-1])
            {
                return false;
            }
        }
        return true;
    }

    bool checkEqual(string s,vector<string>temp)
    {
        vector<int>flex(26,0);
        vector<int>gap(26,0);
        for(int i = 0 ; i < s.size() ; i++ )
        {
            flex[s[i]-'a']++;
        }
        for(int i = 0 ; i < temp.size() ; i++ )
        {
            for(int j = 0 ; j < temp[i].size() ; j++)
            {
                gap[temp[i][j]-'a']++;
            }
        }
        for(int i = 0 ; i < 26 ; i++ )
        {
            if(flex[i] != gap[i])
            {
                return false;
            }
        }

        return true;
    }

    void partition(string s,string p,int ind,vector<string>temp,vector<vector<string>>&ans)
    {
        // p is a temporary String
        if(ind == s.size())
        {
            ans.push_back(temp);
        }

        for(int i = ind ; i < s.size() ; i++)
        {
            p+=s[i];
            if(checkPalindrome(p))
            {
              temp.push_back(p);
              partition(s,"",i+1,temp,ans);
              temp.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        string p;
        partition(s,p,0,temp,ans);
        return ans;
    }
};