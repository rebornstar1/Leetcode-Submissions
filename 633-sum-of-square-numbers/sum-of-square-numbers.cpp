class Solution {
public:
    bool judgeSquareSum(long long c) {
        vector<long long>squares;
        unordered_map<long long,long long>mp;
        set<long long>check;
        squares.push_back(0);
        mp[0]++;
        for(long long i = 1 ; i*i <= (c) ; i++ )
        {
            squares.push_back(i*i);
            mp[i*i]++;
        }
        
        // Checking the c-a*a does exit or not in the set
        unordered_map<long long,long long>temp;
        for(long long i = 0 ; i < squares.size() ; i++ )
        {
            // Required Value is  c-squares[i] respectively
            temp[c-squares[i]]++;
        }

        for(auto it : temp )
        {
           if(mp[it.first] != 0) return true;
        }
        return false;
    }
};

// Currently The Time Complexity is quite high try to resolve that fast