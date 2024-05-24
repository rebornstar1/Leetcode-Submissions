class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        // Instead of Using Vector of Vector You can Declear the Custom Sorting Method
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i = 0 ; i < aliceValues.size() ; i++)
        {
            pq.push({aliceValues[i]+bobValues[i],{aliceValues[i],bobValues[i]}});
        }

        int alice = 0, bob = 0, flag  = 0;
        while(!pq.empty())
        {
            int as = pq.top().second.first;
            int bs = pq.top().second.second;
            pq.pop();
            if(flag == 0)
            {
                alice+=as;
                flag = 1;
            }
            else
            {
                bob+=bs;
                flag = 0;
            }
        }

        if(alice > bob) return 1;
        if(bob > alice) return -1;
        return 0;
    }
};