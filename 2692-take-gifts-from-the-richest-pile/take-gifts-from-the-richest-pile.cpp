class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        int n = gifts.size();
        for(int i = 0 ; i < n ; i++ )
        {
            pq.push(gifts[i]);
        }

        while(k--)
        {
            int num = pq.top();
            pq.pop();
            pq.push(sqrt(num));
        }

        long long ans = 0;
        while(!pq.empty())
        {
            long long val = pq.top();
            ans += val;
            pq.pop();
        }
        return ans;
    }
};

// Now Let's come to more better solution which could be of the Priority Queue