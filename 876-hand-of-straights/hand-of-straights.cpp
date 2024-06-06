class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        sort(hand.begin(),hand.end());
        map<int,int>mp;
        for(int i = 0 ; i < hand.size() ; i++ )
        {
            mp[hand[i]]++;
        }

        int ans = 0;

        for(int i = 0 ; i < hand.size() ; i++ )
        {
            if(mp[hand[i]] == 0) continue;

            for(int j = 0 ; j < groupSize ; j++ )
            {
                if(mp[hand[i]+j] == 0)
                {
                    return false;
                }
                mp[hand[i]+j]--;
            }
        }
        return true;
    }
};