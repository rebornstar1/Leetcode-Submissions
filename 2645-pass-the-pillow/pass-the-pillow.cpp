class Solution {
public:
    int passThePillow(int n, int time) {
        time++;
        int op = (2*n-2);
        int flag = 0;
        if(time%op == 0) flag = 1;
        time = time%op;
        if(flag == 1) time+=op;
        if(time <= n )
        {
            return time;
        }
        return 2*n - time;
    }
};

// n*2 - 2 by which we should take %