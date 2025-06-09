class MyStack {
private:
queue<int>a;
queue<int>b;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        while(!b.empty())
        {
            a.push(b.front());
            b.pop();
        }

        b.push(x);
        while(!a.empty())
        {
            b.push(a.front());
            a.pop();
        }
    }
    
    int pop() {
        int val = b.front();
        b.pop();
        return val;
    }
    
    int top() {
        return b.front();
    }
    
    bool empty() {
        return b.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

 // Implement Stack Using Queue