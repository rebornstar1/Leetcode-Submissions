class Solution {
public:
    int maxDiff(int num) {
        int sizeCheck = to_string(num).size();
        int ans = INT_MIN;
        for(int xi = 0 ; xi <= 9 ; xi++)
        {
            for(int yi = 0 ; yi <= 9 ; yi++)
            {
                for(int xj = 0 ; xj <= 9 ; xj++ )
                {
                    for(int yj = 0 ; yj <= 9 ; yj++ )
                    {
                        // first simplify a number and then b number
                        string as = to_string(num);
                        for(int i = 0 ; i < as.size() ; i++ ) if(as[i] == ('0'+xi)) as[i] = ('0'+yi);
                        int a = stoi(as);

                        string bs = to_string(num);
                        for(int i = 0 ; i < bs.size() ; i++ ) if(bs[i] == ('0'+xj)) bs[i] = ('0'+yj);
                        int b = stoi(bs);

                        if(sizeCheck != to_string(a).size() || sizeCheck != to_string(b).size()) continue;

                        if(a !=0 && b != 0) ans = max(ans,abs(a-b));
                    }
                }
            }
        }
    return ans;
    }
};