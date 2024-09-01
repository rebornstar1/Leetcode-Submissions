class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
       // int wordLen = wordList.size();
       vector<vector<string>>ans;
        
        unordered_map<string,int>AllStrings;
        for(int i = 0 ; i < wordList.size() ; i++ )
        {
            AllStrings[wordList[i]]++;
        }
        AllStrings[beginWord]++;
       // AllStrings[endWord]++;
        // Now I have got all the unique nodes present in the graph

        wordList.clear();
        for(auto it : AllStrings)
        {
            wordList.push_back(it.first);
        }

        // Now we have all the unique strings in the wordList with the beginWord and EndWord
        
        // Graph is Created Here
        unordered_map<string,vector<string>>GraphOfWords;
        for(int i = 0 ; i < wordList.size() ; i++ )
        {
            for(int j = (i+1) ; j < wordList.size() ; j++ )
            {
                if(wordList[i].size() != wordList[j].size()) continue;

                // To count the distinct indices in both the strings
                int cnt = 0;
                for(int k = 0 ; k < wordList[i].size() ; k++ )
                {
                    if(wordList[i][k] != wordList[j][k]) cnt++;
                }

                if(cnt == 1)
                {
                    GraphOfWords[wordList[i]].push_back(wordList[j]);
                    GraphOfWords[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        // dist map to be present here
        unordered_map<string,int>dist;
        for(int i = 0 ; i < wordList.size() ; i++ )
        {
           dist[wordList[i]] = 1000;
        }
        dist[endWord] = 0;

        // Now Count the Minimum Distance Possible for this
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
        pq.push({0,endWord});
        while(!pq.empty())
        {
            int nodeDist = pq.top().first;
            string tempWord = pq.top().second;
            pq.pop();

            for(auto it : GraphOfWords[tempWord])
            {
                if(dist[it] > (nodeDist+1))
                {
                    dist[it] = (nodeDist+1);
                    pq.push({dist[it],it});
                }
            }
        }

        // DO a BFS Traversal from endWord Too to efficiently choose paths which are 
        // feasible from any node itself



        int permissible = dist[beginWord];
        // Now I have the Number of Minimum Words in Any Subsquence Now I can 
        // Do BFS Traversal with the permissible distance

        //cout<<permissible<<endl;
        
        queue<pair<int,vector<string>>>qst;
        qst.push({0,{beginWord}});
        unordered_map<string,int>Vis;

        while(!qst.empty())
        {
           int spec = qst.front().first;
           vector<string>champ = qst.front().second;
           string step = champ[champ.size()-1];
           qst.pop();
           Vis[step]++;

           if(spec == permissible)
           {
               if(champ[champ.size()-1] == endWord)
               {
                  ans.push_back(champ);
               }          
               continue;
            }

            for(auto it : GraphOfWords[step])
            {
                if(Vis[it] == 0 && permissible >= (spec+dist[it]))
                {
                    cout<<it<<" ";
                    champ.push_back(it);
                    qst.push({spec+1,champ});
                    champ.pop_back();
                }
            }
        }
        return ans;
    }
};