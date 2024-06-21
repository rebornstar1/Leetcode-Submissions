class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        int n = customers.size();
        for(int i = 0 ; i < n ; i++ )
        {
            if(grumpy[i] == 0)
            {
                sum += customers[i];
            }
        }

        // Now We will Apply 2 pointer Approach
        int temp = 0, ans = 0;
        int curr = 0, prev = 0;
        while(curr != n)
        {
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