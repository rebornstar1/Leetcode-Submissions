class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return 0;
        int k=sum/2;
        bitset<10001>dp;
        dp[k]=1;
        for(int x:nums){
            dp |= dp>>x;
            if(dp[0]) return 1;
        }
        return dp[0];
    }
};