class Solution {
public:
    // I have to write the compare function to check how many letters are different in both of them
    bool compare(string s,string p)
    {
        // Function has to be written here 
        int cnt = 0;
        for(int i = 0 ; i < min(s.size(),p.size()) ; i++ )
        {
            if(s[i] != p[i]) cnt++;
        }
        return cnt==1?true:false;
    }


    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        // First I Will Check whether endWord is there in the wordList or Not
        bool temp = 0;
        for(int i = 0 ; i < wordList.size() ; i++ )
        {
            if(wordList[i] == endWord)
            {
                temp = 1;
            }
        }
        if(temp == 0) return 0; // If endWord is not present in wordList returning 0 Value

        // To Create The Adjacency List
        wordList.push_back(beginWord);
        wordList.push_back(endWord); 

        int V = wordList.size(); // The Number of Vertices in the graph
        vector<int>dist(V,INT_MAX); // It shows at which index in wordList is there distance from the source

        unordered_map<int,vector<int>>ump;
        for(int i = 0 ; i < V ; i++)
        {
            for(int j = (i+1) ; j < V ; j++)
            {
                if(j!=i)
                {
                    if(compare(wordList[i],wordList[j]))
                    {
                        ump[i].push_back(j);
                        ump[j].push_back(i);
                    }
                }
            }
        }  // done with O(N*N) == (5000*5000) => (2.5*10^7)  
        
        queue<int>qst;
        qst.push(V-2);
        int val = 1;
        while(!qst.empty())
        {
          int n = qst.size();
          for(int j = 0 ; j < n ; j++)
          {
                int node = qst.front();
                qst.pop();
                dist[node] = min(val,dist[node]);
                for(int i = 0 ; i < ump[node].size() ; i++ )
                {
                    if(dist[ump[node][i]] == INT_MAX)
                    {
                        qst.push(ump[node][i]);
                    }
                }
          }
          val++;
        }
        for(int i = 0 ; i < V ; i++ )
        {
            if(dist[i] == INT_MAX)
            {
                dist[i] = 0;
            }
        }
       return dist[V-1]; 
    }
};