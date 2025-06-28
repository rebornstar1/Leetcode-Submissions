class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        int n = nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i = 0 ; i < n ; i++ )
        {
            pq.push({nums[i],i});
            if(pq.size() > k) pq.pop();
        }

        // order of the subsequence could be a possible issue in this
        vector<vector<int>>tempans;
        while(!pq.empty())
        {
            pair<int,int>temp = pq.top();
            tempans.push_back({temp.second,temp.first});
            pq.pop();
        }

        sort(tempans.begin(),tempans.end());

        vector<int>ans;
        for(int i = 0 ; i < tempans.size() ; i++ ) ans.push_back(tempans[i][1]);
        return ans;
    }
};