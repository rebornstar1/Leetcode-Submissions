class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string>vect;
        string temp;
        for(int i = 0 ; i < sentence.size() ; i++ )
        {
            if(sentence[i] != ' ')
            {
                temp += sentence[i];
            }
            else
            {
                vect.push_back(temp);
                temp = "";   
            }
        }
        if(temp!="") vect.push_back(temp);

        map<string,int>mp;

        set<string>pq;

        for(auto it : dictionary)
        {
            mp[it] = 1;
        }

        for(int i = 0 ; i < vect.size() ; i++ )
        {
           string jump;
           for(int j = 0 ; j < vect[i].size() ; j++ )
           {
             jump += vect[i][j];
             if(mp[jump] != 0)
             {
                vect[i] = jump;
                break;
             }
           }
        }

        string ans;
        for(int i = 0 ; i < vect.size() ; i++ )
        {
            ans += vect[i];
            if(i != (vect.size()-1))
            {
                ans += ' ';
            }
        }
        return ans;
    }
};

// Okay It Is Fine but try to reduce the Time Complexity More