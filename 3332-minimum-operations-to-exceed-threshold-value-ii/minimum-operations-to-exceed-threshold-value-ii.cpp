class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2) return 0;

        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(int i =  0 ; i < n ; i++ ) pq.push(nums[i]);

        int cnt = 0;
        while(pq.size() > 1)
        {
            long long num1 = pq.top();
            pq.pop();
            if(num1 >= k) return cnt;
            long long num2 = pq.top();
            pq.pop();
            pq.push(min(num1,num2)*2 + max(num1,num2));
            cnt++;
        }
        return cnt;
    }
};

// min(x,y)*2 + max(x,y) Added for all the operations to be greter than k