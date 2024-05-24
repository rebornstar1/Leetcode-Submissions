class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        // Instead of Using Vector of Vector You can Declear the Custom Sorting Method
        vector<vector<int>>vt;
        for(int i = 0 ; i < n ; i++ )
        {
            vector<int>temp;
            temp.push_back(aliceValues[i]+bobValues[i]);
            temp.push_back(i);
            vt.push_back(temp);
        }
        sort(vt.begin(),vt.end());
        int alice = 0, bob = 0;
        int flag = 0;
        for(int i = (n-1) ; i >= 0 ; i-- )
        {
            if(flag == 0)
            {
                alice+=aliceValues[vt[i][1]];
                flag = 1;
            }
            else
            {
                bob+=bobValues[vt[i][1]];
                flag = 0;
            }
        }

        if(alice > bob) return 1;
        if(bob > alice) return -1;
        return 0;
    }
};