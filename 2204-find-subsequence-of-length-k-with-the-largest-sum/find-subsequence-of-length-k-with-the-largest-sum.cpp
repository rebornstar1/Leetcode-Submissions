class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        int n = nums.size();
        priority_queue<int>pq;

        for(int i = 0 ; i < n ; i++ ) pq.push(nums[i]);

        int num = INT_MIN, freq = 0;
        while(k--)
        {
           if(num == pq.top())
           {
              freq++;
           } 
           else
           {
             num = pq.top();
             freq = 1;
           }

           pq.pop();
        }

        vector<int>ans;
        for(int i = 0 ; i < n ; i++ )
        {
            if(nums[i] > num) ans.push_back(nums[i]);
            else if(nums[i] == num && freq > 0)
            {
               ans.push_back(nums[i]);
               freq--;
            }
        }
        return ans;
    }
};

// The Space Complexity of the Solution Needs to be Reduced