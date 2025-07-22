class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int i = 0 ; i < n ; i++ ) sum += stones[i];

        int target = sum/2;
        // Now I'll try to space Optimize this solution
        vector<int>curr(target+1,0);

        // index => (0 => (n-1))
        // target => (target => 0)

        // Now handle the base case in this properly
        for(int i = 0 ; i <= target ; i++ ) curr[i] = i;

        for(int i = (n-1) ; i >= 0 ; i-- )
        {
            vector<int>prev = curr;
            for(int j = 0 ; j <= target ; j++ )
            {
                prev[j] = min((j >= stones[i] ? curr[j-stones[i]] : INT_MAX),curr[j]);
            }
            curr = prev;
        }

        int achievableTarget = (target-curr[target]);
        return (sum - 2*achievableTarget);
    }
};

// Now I want to space Optimize this solution


