class MyStack {
private:
    std::queue<int> a, b;

public:
    MyStack() {}

    void push(int x) {
        b.push(x);  // Push new element into empty queue b

        // Move all elements from a to b
        while (!a.empty()) {
            b.push(a.front());
            a.pop();
        }

        // Swap a and b so that a always contains the stack order
        std::swap(a, b);
    }

    int pop() {
        if (a.empty()) return -1; // Optional: handle underflow case
        int val = a.front();
        a.pop();
        return val;
    }

    int top() {
        if (a.empty()) return -1; // Optional: handle empty case
        return a.front();
    }

    bool empty() {
        return a.empty();
    }
};
