class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool first_String = false;
        int n = num.size();

        for(int i = 0 ; i < n ; i++ )
        {
            if(first_String)
            {
                if((num[i]-'0') > change[num[i]-'0'])
                {
                    break;
                }
                else
                {
                    num[i] = (change[num[i]-'0']+'0');
                }
            }
            else
            {
                if((num[i]-'0') < change[num[i]-'0'])
                {
                    first_String = true;
                    num[i] = (change[num[i]-'0']+'0');
                }
            }
        }
        return num;
    }
};


// Check If there any optimal Solution exist