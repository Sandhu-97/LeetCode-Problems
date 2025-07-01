struct Node{
    int val;
    Node* next;
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;
    MyLinkedList() {
        head = tail = nullptr; 
        size=0;   
    }
    
    int get(int index) {
        if (index>=size) return-1;
        if (!head) return -1;
        if (index==0) return head->val;

        Node* curr = head;
        for (int i=0;i<index&& curr; i++) curr=curr->next;
        if (!curr) return -1;
        return curr->val;
        
    }
    
    void addAtHead(int val) {
        Node* newnode = new Node{val, head};
        head = newnode;
        if (size==0) tail=newnode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newnode = new Node{val, nullptr};
        // if (!head) {
        //     head = tail = newnode;
        //     size++;
        //     return;
        // }
        // Node* temp = head;
        // while (temp->next) temp=temp->next;
        // temp->next = newnode;
        // size++;

        if (size==0){
            head=tail=newnode;
        } else{
            tail->next = newnode;
            tail=newnode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index==0) {
            addAtHead(val);
            return;
        }
        if (index==size) {
            addAtTail(val);
            return;
        }
        Node* temp = head;
        for (int i=0;i<index-1 && temp; i++){
            temp=temp->next;
        }
        if (!temp) return;
        Node* newnode = new Node{val, temp->next};
        temp->next = newnode;
        size++;
    }
    
    void deleteAtIndex(int index) {
    if (index < 0 || index >= size || !head) return;

    if (index == 0) {
        Node* todel = head;
        head = head->next;
        delete todel;
        size--;
        if (size == 0) tail = nullptr;
        return;
    }

    if (index == size - 1) {
        Node* prev = head;
        for (int i = 0; i < size - 2; i++) prev = prev->next;
        Node* todel = prev->next;
        prev->next = nullptr;
        tail = prev;
        delete todel;
        size--;
        return;
    }

    Node* curr = head;
    for (int i = 0; i < index - 1 && curr; i++) curr = curr->next;
    if (!curr || !curr->next) return;

    Node* todel = curr->next;
    curr->next = curr->next->next;
    delete todel;
    size--;
}

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */