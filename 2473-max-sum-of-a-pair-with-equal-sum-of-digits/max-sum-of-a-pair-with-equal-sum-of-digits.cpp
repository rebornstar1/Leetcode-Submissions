class Solution {
public:
    int sumOfDigits(int num)
    {
        int result = 0;
        while(num != 0)
        {
            result += (num%10);
            num /= 10;
        }
        return result;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>mp;
        for(int i = 0 ; i < n ; i++ )
        {
            int valOfDigits = sumOfDigits(nums[i]);
            mp[valOfDigits].push(nums[i]);
            if(mp[valOfDigits].size() > 2) mp[valOfDigits].pop();
        }

        int ans = -1;
        for(auto it : mp)
        {
            if(it.second.size() == 0) continue;
            int num1 = it.second.top();
            it.second.pop();
            if(it.second.size() == 0) continue;
            int num2 = it.second.top();
            it.second.pop();
            ans = max(ans,num1+num2);
        }
        return ans;
    }
};

// Try If You Can Optimise this code further