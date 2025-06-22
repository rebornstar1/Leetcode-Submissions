class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        int n = s.size();
        for(int i = 0 ; i < n ; i+= k)
        {
            if((i+k-1) >= n)
            {
               string temp = s.substr(i,n-i);
               int flex = (n-i);
               while(flex != k)
               {
                 temp += fill;
                 flex++;
               }
               ans.push_back(temp);
            }
            else
            {
              ans.push_back(s.substr(i,k));
            }
        }
        return ans;
        
    }
};