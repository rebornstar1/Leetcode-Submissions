class Solution {
public:
    void func(int ind,set<int>&st, vector<int>& costs,vector<int>&dp)
    {
        if(ind == 366) return;

        if(st.find(ind) == st.end())
        {
            cout<<ind<<" "<<"if"<<endl;
           // the day not travelled
           dp[ind] = min(dp[ind-1],dp[ind]);
           func(ind+1,st,costs,dp);
        }
        else
        {
            cout<<ind<<" "<<"else"<<endl;
           // the days travelled
           
           // 1-day pass
           dp[ind] = min(dp[ind],dp[ind-1]+costs[0]);

           // 7-day pass
           for(int i = 0 ; i < 7 ; i++ )
           {
               dp[ind+i] = min(dp[ind+i],dp[ind-1]+costs[1]);
           }

           // 30-day pass
           for(int i = 0 ; i < 30 ; i++ )
           {
               dp[ind+i] = min(dp[ind+i],dp[ind-1]+costs[2]);
           }
           func(ind+1,st,costs,dp);
        }
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        sort(days.begin(),days.end());
        vector<int>dp(400,INT_MAX);
        dp[0] = 0;
        set<int>st;
        for(int i = 0 ; i < days.size() ; i++ )
        {
            st.insert(days[i]);
        }
       func(1,st,costs,dp);
       for(int i = 0 ; i <= 25 ; i++ )
       {
          cout<<dp[i]<<" "<<i<<endl;
       }
       int day_size = days.size();
       return dp[days[day_size-1]];
    }
};