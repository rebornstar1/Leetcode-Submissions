class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
         vector<int>freq(26,0);
         for(int i = 0 ; i < words2.size() ; i++ )
         {
            vector<int>temp_freq(26,0);
            for(int j = 0 ; j < words2[i].size() ; j++ )
            {
                temp_freq[words2[i][j]-'a']++;
            }

            for(int i = 0 ; i < 26 ; i++ )
            {
                freq[i] = max(freq[i],temp_freq[i]);
            }
         }

         words2.clear();
         for(int i = 0 ; i < words1.size() ; i++ )
         {
            vector<int>temp_freq(26,0);
            for(int j = 0 ; j < words1[i].size() ; j++ )
            {
                temp_freq[words1[i][j]-'a']++;
            }

            bool flex = true;
            for(int k = 0 ; k < 26 ; k++ )
            {
                if(temp_freq[k] < freq[k])
                {
                    flex = false;
                }
            }

            if(flex) words2.push_back(words1[i]);
         }

        return words2;
    }
};