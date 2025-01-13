class Solution {
public:
    long long solve(vector<int>& strength, int x, int terms, int k, int bits) {
        if (terms == strength.size()) return 0; // Base case: all terms used

        long long val = LLONG_MAX; // Use LLONG_MAX for long long type
        for (int i = 0; i < strength.size(); i++) {
            // Check if the i-th index is not used
            if (!((bits >> i) & 1)) {
                // Calculate time for current index
                long long time = (strength[i] + x - 1) / x; // Equivalent to ceiling(strength[i] / x)
                // Recurse with updated bitmask and incremented divisor
                val = min(val, time + solve(strength, x + k, terms + 1, k, bits | (1 << i)));
            }
        }
        return val;
    }

    long long findMinimumTime(vector<int>& strength, int k) {
        return solve(strength, 1, 0, k, 0); // Start with x = 1, terms = 0, and no bits set
    }
};


// Apply the Bitmasking here