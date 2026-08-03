class MyQueue {
public:
    stack<int> s1;
    MyQueue() {
        
    }
    
    void push(int x) {
        if (s1.size()<=0) {
            s1.push(x);
            return;
        }
        int top = s1.top();
        s1.pop();
        push(x);
        s1.push(top);
    }
    
    int pop() {
        int top = s1.top();
        s1.pop();
        return top;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
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