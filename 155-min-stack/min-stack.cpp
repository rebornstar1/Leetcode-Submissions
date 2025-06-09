class MinStack {
private:
    stack<int> st;
    stack<pair<int, int>> minSt; // {minValue, frequency}
public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        if(minSt.empty() || val < minSt.top().first)
            minSt.push({val, 1});
        else if(val == minSt.top().first)
            minSt.top().second++; // Increase frequency
    }

    void pop() {
        if(st.top() == minSt.top().first) {
            minSt.top().second--;
            if(minSt.top().second == 0)
                minSt.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top().first;
    }
};
