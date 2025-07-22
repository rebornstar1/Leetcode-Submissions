class Solution {
private:
    vector<string> ans;

    void backtrack(string &num, int target, int index, long long currVal, long long prevOperand, string expression) {
        if (index == num.size()) {
            if (currVal == target) ans.push_back(expression);
            return;
        }

        for (int i = index; i < num.size(); ++i) {
            if (i != index && num[index] == '0') break;

            string part = num.substr(index, i - index + 1);
            long long val = stoll(part);

            if (index == 0) {
                backtrack(num, target, i + 1, val, val, part);
            } else {
                backtrack(num, target, i + 1, currVal + val, val, expression + "+" + part);

                backtrack(num, target, i + 1, currVal - val, -val, expression + "-" + part);

                backtrack(num, target, i + 1,
                          currVal - prevOperand + prevOperand * val,
                          prevOperand * val,
                          expression + "*" + part);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        ans.clear();
        string expr;
        backtrack(num, target, 0, 0, 0, expr);
        return ans;
    }
};
