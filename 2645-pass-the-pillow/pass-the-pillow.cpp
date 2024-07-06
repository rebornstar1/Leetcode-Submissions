class Solution {
public:
    int passThePillow(int n, int time) {
        vector<int>temp;
        for(int i = 1 ; i <= n ; i++ )
        {
            temp.push_back(i);
        }
        for(int i = (n-1) ; i > 1 ; i-- )
        {
            temp.push_back(i);
        }

        int flex = temp.size();
        int ind = 0;
        int cnt = 0;
        while(cnt != time)
        {
            ind++;
            cnt++;
            ind%=flex;
        }
        return temp[ind];
    }
};

// n*2 - 2 by which we should take %