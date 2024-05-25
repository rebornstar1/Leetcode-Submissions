class Solution {
public:
    void check(int ind,string s,set<string>&qst, vector<string>&champ, vector<vector<string>>&ans)
    {
        if(ind == s.size())
        {
            ans.push_back(champ);
            return;
        }

        string cp;
        for(int i = ind ; i < s.size() ; i++ )
        {
            cp+=s[i];
            if(qst.find(cp) != qst.end())
            {
                champ.push_back(cp);
                check(i+1,s,qst,champ,ans);
                champ.pop_back();
            }
        }
    }
 
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Finding the Maximum Length Word in wordDict
        int n = 0;
        set<string>qst;
        for(int i = 0 ; i < wordDict.size() ; i++ )
        {
            int p = wordDict.size();
            n = max(n,p);
            qst.insert(wordDict[i]);
        }
        string temp;
        vector<vector<string>>ans;
        vector<string>champ;
        check(0,s,qst,champ,ans);
        
        vector<string>jump;
        for(int i = 0 ; i < ans.size() ; i++ )
        {
            string keep;
            for(int j = 0 ; j < ans[i].size() ; j++)
            {
              keep+=ans[i][j];
              if(j != ans[i].size()-1) keep+=' ';
            }
            jump.push_back(keep);
        }
        return jump;
    }
};