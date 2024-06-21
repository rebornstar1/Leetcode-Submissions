class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        int n = customers.size();

        // Now We will Apply 2 pointer Approach
        int temp = 0, ans = 0;
        int curr = 0, prev = 0;
        while(curr != n)
        {
            if(grumpy[curr] == 0)
            {
                sum += customers[curr];
            }

            if((curr-prev) < minutes)
            {
                if(grumpy[curr] == 1){
                temp += customers[curr];
                ans = max(ans,temp);
                }
                curr++;
            }
            else if((curr-prev) == minutes)
            {
               if(grumpy[curr] == 1){
                temp += customers[curr];
                }
                if(grumpy[prev] == 1)
                {
                temp -= customers[prev];
                }
                ans = max(ans,temp);
                curr++;
                prev++;
            }
        }
        return ans+sum;
    }
};

// Think About Can you optimise It More ?
