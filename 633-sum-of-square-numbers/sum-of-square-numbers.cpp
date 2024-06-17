class Solution {
public:
    bool judgeSquareSum(long long c) {
        vector<long long>squares;
        set<long long>check;
        squares.push_back(0);
        for(long long i = 1 ; i*i <= (c) ; i++ )
        {
            squares.push_back(i*i);
            check.insert(i*i);
        }

        for(auto it : squares)
        {
            cout<<it<<" ";
        }
        
        // Checking the c-a*a does exit or not in the set
        for(long long i = 0 ; i < squares.size() ; i++ )
        {
            if(check.find(c-squares[i]) != check.end() || c == squares[i])
            {
                return true;
            }
        }
        return false;
    }
};