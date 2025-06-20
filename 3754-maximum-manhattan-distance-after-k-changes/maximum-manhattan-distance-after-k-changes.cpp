class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0; // Initially present at the origin
        
        int n = s.size();
        
        // NE 
        int temp1 = 0, tempk = k;
        for(int i = 0 ; i < n ; i++ )
        {
            if((s[i] == 'N') || (s[i] == 'E'))
            {
                 temp1++;
            }
            else
            {
                if(tempk!=0)
                {
                    tempk--;
                    temp1++;
                }
                else
                {
                    temp1--;
                }
            }
            ans = max(ans,temp1);
        }
        
        // NW
        int temp2 = 0;
        tempk = k;
        for(int i = 0 ; i < n ; i++ )
        {
            if((s[i] == 'N') || (s[i] == 'W'))
            {
                 temp2++;
            }
            else
            {
                if(tempk!=0)
                {
                    tempk--;
                    temp2++;
                }
                else
                {
                    temp2--;
                }
            }
            ans = max(ans,temp2);
        }
        
        // SE
        int temp3 = 0;
        tempk = k;
        for(int i = 0 ; i < n ; i++ )
        {
            if((s[i] == 'S') || (s[i] == 'E'))
            {
                 temp3++;
            }
            else
            {
                if(tempk!=0)
                {
                    tempk--;
                    temp3++;
                }
                else
                {
                    temp3--;
                }
            }
            ans = max(ans,temp3);
        }
        
        // SW
        int temp4 = 0;
        tempk = k;
        for(int i = 0 ; i < n ; i++ )
        {
            if((s[i] == 'S') || (s[i] == 'W'))
            {
                 temp4++;
            }
            else
            {
                if(tempk!=0)
                {
                    tempk--;
                    temp4++;
                }
                else
                {
                    temp4--;
                }
            }
            ans = max(ans,temp4);
        }
        
        return ans;
    }
};