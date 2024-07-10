class Solution {
public:
    int iDentify(string &temp)
    {
         if(temp.size() == 2)
         {
            if(temp[0] == '.' && temp[1] == '/') return 2;
            return 3;
         }
         if(temp[0] == '.' && temp[1] == '.' && temp[2] == '/') return 1;
         return 3;
    }
 
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for(int i = 0 ; i < logs.size() ; i++ )
        {
            int flag = iDentify(logs[i]);

            if(flag == 1)
            {
                cnt = max(cnt-1,0);
            }
            else if(flag == 3)
            {
                cnt++;
            }
        }
        return cnt;
    }
};