class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        // Greedy Approach in this question

        sort(horizontalCut.begin(),horizontalCut.end());
        sort(verticalCut.begin(),verticalCut.end());

        int h = 1 , v = 1 , ind1 = (m-1) , ind2 = (n-1);
        long long ans = 0;

        while((ind1 != 0 ) || (ind2 != 0))
        {
            if(ind1 == 0)
            {
               ans += (verticalCut[ind2-1]*h);
               ind2--;
               v++;
            }
            else if(ind2 == 0)
            {
               ans += (horizontalCut[ind1-1]*v);
               ind1--;
               h++;
            }
            else
            {
                if(horizontalCut[ind1-1] >= verticalCut[ind2-1])
                {
                    ans += (horizontalCut[ind1-1]*v);
                    ind1--;
                    h++;
                }
                else
                {
                    ans += (verticalCut[ind2-1]*h);
                    ind2--;
                    v++;
                }
            }
        }
        return ans;
    }
};