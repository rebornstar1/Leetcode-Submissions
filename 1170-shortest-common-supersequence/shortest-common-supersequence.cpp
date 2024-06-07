class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        // write the same lcs printing code here
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i = 1 ; i <= n ; i++ ) dp[i][0] = 0;
        for(int j = 1 ; j <= m ; j++ ) dp[0][j] = 0;
        dp[0][0] = 0;

        for(int i = 1 ; i <= n ; i++ )
        {
            for(int j = 1 ; j <= m ; j++ )
            {
                if(str1[i-1] == str2[j-1])
                {
                    dp[i][j] = (1+dp[i-1][j-1]);
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

    int ind1 = n;
    int ind2 = m;
    string p;
    while(ind1 > 0 && ind2 > 0)
    {
        if(str1[ind1-1] == str2[ind2-1])
        {
            p += str1[ind1-1];
            ind1--;
            ind2--;
        }
        else
        {
            if(dp[ind1-1][ind2] > dp[ind1][ind2-1])
            {
            ind1--;
            }
            else
            {
            ind2--;
            }
        }
        // cout<<p<<" "<<ind1<<" "<<ind2<<endl;
    }

    reverse(p.begin(),p.end());
    cout<<p<<endl;
    //return p;
    // So here p is the longest common subsequence
    int inx = 0 , i = 0 , j = 0;
    string ans;
    while( (i != n) && (j != m))
    {
        if(str1[i] == p[inx] && str2[j] == p[inx])
        {
            ans += str1[i];
            i++;
            j++;
            inx++;
        }
        else if(str1[i] == p[inx])
        {
            ans += str2[j];
            j++;
        }
        else if(str2[j] == p[inx])
        {
            ans += str1[i];
            i++;
        }
        else
        {
            ans += str1[i];
            ans += str2[j];
            i++;
            j++;
        }
        //cout<<ans<<endl;
    }

    for(int k = i ; k < n ; k++ )
    {
        ans += str1[k];
    }
    for(int k = j ; k < m ; k++ )
    {
        ans += str2[k];
    }

    return ans;
    }
};