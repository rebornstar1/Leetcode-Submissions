class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>vect(n,0);
        for(int i = 0 ; i < n ; i++ ) vect[i] = (i+1);

        // If It's Visited Make it -1 
        int cnt = 0; // Cnt of Nodes Visited

        int temp = 0,ind = 0;
        while(cnt != (n-1))
        {
             if(vect[ind%n] != -1)
             {
                temp++;
                if(temp == k)
                {
                    vect[ind%n] = -1;
                    cnt++;
                    temp = 0;
                }
             }
             ind++;
        }

        for(int i = 0 ; i < n ; i++ ) if(vect[i] != -1) return (i+1);
        return 0;
    }
};

// First Write the Bruteforce Solution for this