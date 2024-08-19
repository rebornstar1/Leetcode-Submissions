class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        int ind = 2;
        while(n != 1)
        {
           if(n%ind == 0)
           {
              n/=ind;
              ans += ind;
           }
           else
           {
              ind++;
           }
        }
        return ans;
    }
};

// Copy All the Characters