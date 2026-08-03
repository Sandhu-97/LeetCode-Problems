class MyCircularQueue {
public:
    int front,rear,capacity,size;
    vector<int> q;
    MyCircularQueue(int k) {
        capacity=k;
        size=0;
        front=0;
        rear=0;
        q.resize(k); 
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        q[rear]=value;
        size++;
        rear=(rear+1)%capacity;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        front=(front+1)%capacity;
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty()? -1 : q[front];
    }
    
    int Rear() {
        return isEmpty()? -1 : q[(rear - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        if (size==0) return true;
        return false;
    }
    
    bool isFull() {
        if (capacity==size) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */