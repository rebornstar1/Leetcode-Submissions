class MinStack {
private:
   stack<int> st1,st2;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st1.size() == 0) 
        {
            st1.push(val);
            st2.push(val);
            return;
        }

        st1.push(val);
        if(st2.top() >= val) st2.push(val);
    }
    
    void pop() {
        int val = st1.top();
        st1.pop();
        if(st2.empty()) return;
        if(val == st2.top()) st2.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};

// Think of Any Optimal Solution which could exist for this itself

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */