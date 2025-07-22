class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        
        int curr_score = 0, max_score = 0, i = 0, j = -1, unique = 0;

        // we also need to carefully have the count of the unique
        
        while(j != n)
        {
            int sizeOfMap = mp.size();
            if(sizeOfMap == unique)
            {
                // now we can take it and then add up something in it
                max_score = max(max_score,curr_score);
                j++;
                if(j == n) break;
                curr_score += nums[j];
                mp[nums[j]]++;
                if(mp[nums[j]] == 1) unique++;
                else unique--;
            }
            else
            { 
                mp[nums[i]]--;
                if(mp[nums[i]] == 1) unique++;
                if(mp[nums[i]] == 0)
                {
                    mp.erase(nums[i]);
                    unique--;
                } 
                curr_score -= nums[i];
                i++;
            }
        }
        return max_score;
    }
};

// Find for any edge case in this problem if available