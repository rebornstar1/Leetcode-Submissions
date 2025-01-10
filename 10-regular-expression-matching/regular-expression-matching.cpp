class Solution {
public:
    bool solve(string &s, string &p, int i, int j) {
        // Base Case: Both strings are fully processed
        if (j == p.size()) {
            return i == s.size();
        }

        // Check if the current characters match
        bool currentMatch = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        // Handle '*' in the pattern
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Match zero occurrences or one/more occurrences
            return solve(s, p, i, j + 2) || (currentMatch && solve(s, p, i + 1, j));
        }

        // Proceed if characters match
        if (currentMatch) {
            return solve(s, p, i + 1, j + 1);
        }

        // No match
        return false;
    }

    bool isMatch(string s, string p) {
        return solve(s, p, 0, 0);
    }
};


// First Write the recursive code for the problem