class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();

        int tempVal = 0, ans = 1;
        char tempChar = '#';

        for(int i = 0 ; i < n ; i++ )
        {
           if(word[i] == tempChar)
           {
               tempVal++;
           }
           else
           {
              ans += max(0,tempVal-1);
              tempVal = 1;
              tempChar = word[i];
           }
        }

        ans += max(0,tempVal-1);

        return ans;
    }
};