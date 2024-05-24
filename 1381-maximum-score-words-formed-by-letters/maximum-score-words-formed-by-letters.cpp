class Solution {
public:
    // Take Not Take Approach Should be considered Here
    int recurseit(vector<string>&words, map<char,int>&mp, vector<int>&score, int ind)
    {
        if(ind == words.size())
        {
            // Base Case
            return 0;
        }
        int val = 0;
        // First Not Take Approach
        val = recurseit(words,mp,score,ind+1);

        // Then Take Appoach
        int flag = 0;
        int temp = 0;
        for(int i = 0 ; i < words[ind].size() ; i++ )
        {
            if(mp[words[ind][i]] == 0)
            {
                flag = ((i+1)*(-1)); // flag i means words can't be formed
                break;
            }
            else
            {
                mp[words[ind][i]]--;
                temp += score[words[ind][i]-'a'];
            }
        }
        if(flag >= 0)
        {
            temp += recurseit(words,mp,score,ind+1);
            for(int i = 0 ; i < words[ind].size() ; i++ )
            {
                mp[words[ind][i]]++;
            }
            val = max(val,temp);
        }
        else
        {
            flag*=(-1);
            flag--;
            // To Extract The Original Value for it
            for(int i = 0 ; i < flag ; i++ )
            {
                mp[words[ind][i]]++;
            }
        }
        return val;
    }
    

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<char,int>mp;
        for(int i = 0 ; i < letters.size() ; i++ )
        {
            mp[letters[i]]++;
        }
        return recurseit(words,mp,score,0);
    }
};