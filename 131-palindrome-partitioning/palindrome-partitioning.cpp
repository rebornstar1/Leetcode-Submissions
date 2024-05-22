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

    void partition(string s,string p,int ind,vector<string>temp,set<vector<string>>&ans,int flag)
    {
        // p is a temporary String
        if(ind == s.size())
        {
            if(checkEqual(s,temp))
            {
             ans.insert(temp);
            }
            return;
        }

        p+=s[ind];
        if(checkPalindrome(p))
        {
            if(flag == 1)
            {
                temp.pop_back();
            }
            temp.push_back(p);
        }
        partition(s,"",ind+1,temp,ans,0);
        partition(s,p,ind+1,temp,ans,1);
        return;
    }

    vector<vector<string>> partition(string s) {
        set<vector<string>>ans;
        vector<string>temp;
        string p;
        vector<vector<string>>haup;
        int flag = 0;
        partition(s,p,0,temp,ans,flag);
        for(auto it : ans)
        {
            haup.push_back(it);
        }
        return haup;
    }
};