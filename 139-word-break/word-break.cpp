class Solution {
public:
    bool checkBreak(string &s, string temp , set<string>&qst,int ind,map<pair<int,string>,bool>&dp)
    {
        if(ind == s.size())
        {
            cout<<temp<<endl;
            if(qst.find(temp) != qst.end()) return true;
            return false;
        }

        if(dp.find({ind,temp}) != dp.end())
        {
            return dp[{ind,temp}];
        }

        if(qst.find(temp) != qst.end())
        {
            return dp[{ind,temp}] = (checkBreak(s,"",qst,ind,dp)|checkBreak(s,temp+s[ind],qst,ind+1,dp));
        }
        else
        {
            return dp[{ind,temp}] = (checkBreak(s,temp+s[ind],qst,ind+1,dp));
        }
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // I Need To Write a recursive code for this maybe
        set<string>qst;
        for(int i = 0 ; i < wordDict.size() ; i++ )
        {
            qst.insert(wordDict[i]);
        }
        int n = s.size();
        map<pair<int,string>,bool>dp;
        return checkBreak(s,"",qst,0,dp);
    }
};

// Aware of this fact