class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        multiset<int>st;
        int ans = 0;
        for(int i = 0 ; i <= n ; i++ )
        {
            int val = 0, flex = eventTime;
            if(i < n) flex = startTime[i];
            if(i > 0) val = endTime[i-1];
            st.insert(flex-val);
        }

        // now we have all the gaps in between of it

        for(int i = 0 ; i < n ; i++ )
        {
            int x1;
            int x2;
            if(i == 0)
            {
               x1 = (startTime[i]);
               x2 = (startTime[i+1]-endTime[i]);
            }
            else if(i == (n-1))
            {
               x1 = (startTime[i]-endTime[i-1]);
               x2 = (eventTime-endTime[i]);
            }
            else
            {
               x1 = (startTime[i]-endTime[i-1]);
               x2 = (startTime[i+1]-endTime[i]);
            }

            auto it1 = st.find(x1);
            st.erase(it1);
            auto it2 = st.find(x2);
            st.erase(it2);

            auto it = st.end();
            it--;
            if((*it) >= (endTime[i]-startTime[i])) ans = max(ans,x1+x2+(endTime[i]-startTime[i]));
            else ans = max(ans,x1+x2);

            st.insert(x1);
            st.insert(x2);
        }

        return ans;
    }
};