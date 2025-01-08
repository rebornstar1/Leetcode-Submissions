class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        // Naive Approach O(50*50*10)

        int ans = 0, n = words.size();
        for(int i = 0 ; i < n ; i++ )
        {
            for(int j = (i+1) ; j < n ; j++ )
            {
                if(words[i].size() > (words[j].size())) continue;
                bool temp = true;
                // now the prefix to be checked
                for(int k = 0 ; k < words[i].size() ; k++ )
                {
                   if(words[i][k] != words[j][k]) temp = false;
                }
                
                // now the suffix to be checked
                for(int k = 0 ; k < words[i].size() ; k++ )
                {
                    if(words[i][k] != words[j][words[j].size()-words[i].size()+k]) temp = false;
                }

                if(temp) ans++;
            }
        }
        return ans;
    }
};

// str1 should be prefix and suffix of str2 respectively