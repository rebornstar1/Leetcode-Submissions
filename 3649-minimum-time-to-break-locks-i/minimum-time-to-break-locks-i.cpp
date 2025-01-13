class Solution {
public:
    int solve(vector<int>&strength, int x, int terms, int k)
    {
        if(terms == strength.size()) return 0;

        int val = INT_MAX;
        for(int i = 0 ; i < strength.size() ; i++ )
        {
            if(strength[i] != INT_MAX)
            {
                int temp = strength[i];
                strength[i] = INT_MAX;

                if(temp%x == 0)
                {
                  val = min(val,(temp/x) + solve(strength, x+k, terms+1 , k)) ;
                }
                else
                {
                  val = min(val,(temp/x + 1) + solve(strength, x + k, terms+1, k));
                }
                strength[i] = temp;
            }
        }
        return val;
    }

    int findMinimumTime(vector<int>& strength, int k) {
        int n = strength.size();
        int x = 1, time = 0;
        return solve(strength,x,0,k);
    }
};

// Your Goal is to remove the Redundant States

// Try Making All permutations of the strength Array here