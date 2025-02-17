class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        int ans = 0;

        vector<int>factorial(10,1);
        for(int i = 1 ; i <= 9 ; i++ )
        {
            factorial[i] = (i*factorial[i-1]);
        }

        vector<int>freq(30,0);
        for(int i = 0 ; i < n ; i++ )
        {
            freq[tiles[i]-'A']++;
        }

        queue<vector<int>>qst;

        for(int i = 0 ; i <= freq[0] ; i++ )
        {
            qst.push({i});
        }


        int temp = 1;
        while(temp < 26)
        {
            int p = qst.size();
            while(p--)
            {
                vector<int>flex = qst.front();
                qst.pop();

                for(int i = 0 ; i <= freq[temp] ; i++ )
                {
                    flex.push_back(i);
                    qst.push(flex);
                    flex.pop_back();
                }
            }
            temp++;
        }
   
        while(!qst.empty())
        {
           vector<int>flex = qst.front();
           qst.pop();

           int val = 1, hop = 0;
           for(int i = 0 ; i < flex.size() ; i++ )
           {
              val *= factorial[flex[i]];
              hop += flex[i];
           }
            
           ans += (factorial[hop]/val);
        }
        return ans-1;
    }
};

// 2 & 1

// Possible Configurations are 
// 2 1 => 3!/2!
// 1 1 => 2!
// 0 1 => 1!
// 2 0 => 1!
// 1 0 => 1!

// So basically we Got 8 configurations by this way