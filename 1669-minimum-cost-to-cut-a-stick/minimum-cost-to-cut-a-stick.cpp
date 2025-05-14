class Solution {
public:
    int func(int left, int right, vector<int>& cuts, vector<vector<int>>& dp) {
        if (right - left <= 1) return 0;
        
        if (dp[left][right] != -1) return dp[left][right];
        
        int minCost = INT_MAX;
        
        for (int k = left + 1; k < right; k++) {
            int cost = cuts[right] - cuts[left] + 
                      func(left, k, cuts, dp) + 
                      func(k, right, cuts, dp);
            
            minCost = min(minCost, cost);
        }
        
        return dp[left][right] = minCost;
    }
    
    int minCost(int n, vector<int>& cuts) {
        vector<int> allCuts = {0};
        for (int cut : cuts) allCuts.push_back(cut);
        allCuts.push_back(n);
        
        sort(allCuts.begin(), allCuts.end());
        
        int size = allCuts.size();
        vector<vector<int>> dp(size, vector<int>(size, -1));
        
        return func(0, size - 1, allCuts, dp);
    }
};