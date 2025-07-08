class CustomStack {
public:
    int maxSize;
    int size;
    vector<int> vec;
    CustomStack(int maxSize) {
        this->maxSize=maxSize;
        size=0;
    }
    
    void push(int x) {
        if (size<maxSize){
            vec.push_back(x);
            size++;
        }
    }
    
    int pop() {
        if (size==0) return -1;
        int top = vec.back();
        vec.pop_back();
        size--;
        return top;

    }
    
    void increment(int k, int val) {
        if (k>=size) k=size;
        for (int i=0;i<k;i++){
            vec[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */