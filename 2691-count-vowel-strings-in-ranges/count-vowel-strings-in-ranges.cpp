class Solution {
public:
    void makeTest(unordered_set<char>&test)
    {
        test.insert('a');
        test.insert('e');
        test.insert('i');
        test.insert('o');
        test.insert('u');
        return;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>prefix;
        unordered_set<char>test;
        makeTest(test);
        prefix.push_back(0);

        for(int i = 0 ; i < words.size() ; i++ )
        {
            if(test.find(words[i][0]) != test.end() && test.find(words[i][words[i].size()-1]) != test.end())
            {
                prefix.push_back(prefix[i]+1);
            }
            else
            {
                prefix.push_back(prefix[i]+0);
            }
        }

        vector<int>ans;
        for(int i = 0 ; i < queries.size() ; i++ )
        {
            int u = queries[i][0];
            int v = queries[i][1];
            
            int temp = (prefix[v+1]-prefix[u+1]);
            if(test.find(words[u][0]) != test.end() && test.find(words[u][words[u].size()-1]) != test.end())
            {
                temp++;
            }
            ans.push_back(temp);
        }

        return ans;
    }
};