class Solution {
public:
    bool check(vector<int> &position,int md,int m)
    {
        int temp = position[0];
        int val = 1;
        while(val <= m)
        {
            auto it = lower_bound(position.begin(),position.end(),md+temp);
            if(it != position.end())
            {
                val++;
                temp = *it;
            }
            else
            {
               break;
            }
        }
        return val >= m;
    }

    int maxDistance(vector<int>& position, int m) {

        int n = position.size();
        sort(position.begin(),position.end());
        // This seems of Binary Search
        int s = 1 , e = 1e9, md;
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

// Reduce the Time & Space Complexity Now