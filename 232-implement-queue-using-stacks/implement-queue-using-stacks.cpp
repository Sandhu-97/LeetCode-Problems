class MyQueue {
public:
    stack<int> st1;
    MyQueue() {
        
    }
    
    void push(int x) {
        if (st1.size()<=0) {
            st1.push(x);
            return;
        }
        int top = st1.top();
        st1.pop();
        push(x);
        st1.push(top);
    }
    
    int pop() {
        int x = st1.top();
        st1.pop();
        return x;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */