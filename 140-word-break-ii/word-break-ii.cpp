class Solution {
public:
    void check(int ind,string s,set<string>&qst, string champ, vector<string>&ans)
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
                string houp = champ;
                champ+=cp;
                if(i != s.size()-1) champ+=' ';
                check(i+1,s,qst,champ,ans);
                champ = houp;
            }
        }
    }
 
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Finding the Maximum Length Word in wordDict
        set<string>qst;
        for(int i = 0 ; i < wordDict.size() ; i++ )
        {
            int p = wordDict.size();
            qst.insert(wordDict[i]);
        }
        string temp;
        vector<string>ans;
        string champ;
        check(0,s,qst,champ,ans);
        
        return ans;
    }
};