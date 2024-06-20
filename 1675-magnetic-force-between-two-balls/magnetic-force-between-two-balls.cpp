class Solution {
public:
    bool check(multiset<int> &qst,int md,int m)
    {
        int temp = *(qst.begin());
        int val = 1;
        while(val <= m)
        {
            auto it = qst.lower_bound(md+temp);
            if(it != qst.end())
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
        multiset<int>qst;
        for(int i = 0 ; i < n ; i++ )
        {
            qst.insert(position[i]);
        }
        // This seems of Binary Search
        int s = 1 , e = 1e9, md;
        while((e-s)>1)
        {
            int md = (s+e)/2;
            if(check(qst,md,m))
            {
               s = md;
            }
            else
            {
               e = (md-1);
            }
        }

        if(check(qst,e,m))
        {
            return e;
        }
        else
        {
            return s;
        }
    }
};