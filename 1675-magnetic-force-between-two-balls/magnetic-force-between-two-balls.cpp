class Solution {
public:
    bool check(vector<int> &position,int md,int m)
    {
        int temp = position[0];
        int cnt = 1;
        // Directly Try Only one for loop
        for(int i = 1 ; i < position.size() ; i++ )
        {
            if((position[i]-temp) >= md)
            {
               cnt++;
               temp = position[i];
            }
        }
        return cnt >= m;
    }

    int maxDistance(vector<int>& position, int m) {

        int n = position.size();
        sort(position.begin(),position.end());
        // This seems of Binary Search
        int s = 1 , e = (position[n-1]-position[0]), md;
        while((e-s)>1)
        {
            int md = (s+e)/2;
            if(check(position,md,m))
            {
               s = md;
            }
            else
            {
               e = (md-1);
            }
        }

        if(check(position,e,m))
        {
            return e;
        }
        else
        {
            return s;
        }
    }
};

// Check If It can be more optimised or not