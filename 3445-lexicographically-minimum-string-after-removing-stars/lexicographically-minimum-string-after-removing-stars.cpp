class Solution {
public:
    struct Comp {
        bool operator()(pair<char,int> &pair1, pair<char,int> &pair2)
        {
            if(pair1.first > pair2.first) return true;
            if(pair1.first < pair2.first) return false;

            return pair1.second < pair2.second;
        }
    };

    string clearStars(string s) {
        int n = s.size();
        priority_queue<pair<char,int>,vector<pair<char,int>>,Comp>qst;
        vector<int>flex;

        for(int i = 0 ; i < n ; i++ )
        {
            if(s[i] != '*')
            {
               qst.push({s[i],i});
            }
            else
            {
                pair<char,int>temp = qst.top();
                qst.pop();
                flex.push_back(temp.second);
            }            
        }

        for(int i = 0 ; i < flex.size() ; i++ )
        {
            s[flex[i]] = '*';
        }

        string ans;
        for(int i = 0 ; i < n ; i++ )
        {
            if(s[i] != '*') ans += s[i];
        }
        return ans;
    }
};