class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>ans(26,INT_MAX);
        for(int i = 0 ; i < words.size() ; i++ )
        {
           vector<int>temp(26,0);
           for(int j = 0 ; j < words[i].size() ; j++ )
           {
              temp[words[i][j]-'a']++;
           }
           for(int j = 0 ; j < 26 ; j++ )
           {
              ans[j] = min(ans[j],temp[j]);
           }
        }
        words.clear();
        for(int i = 0 ; i < 26 ; i++ )
        {
            int check = ans[i];
            while(check != 0)
            {
                string k;
                k += ('a'+i);
                words.push_back(k);
                check--;
            }
        }
        return words;
    }
};