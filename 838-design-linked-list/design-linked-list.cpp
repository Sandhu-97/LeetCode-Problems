struct Node{
    int val;
    Node* next;
};

class MyLinkedList {
public:
    Node* head;
    int size;
    MyLinkedList() {
        head = nullptr; 
        size=0;   
    }
    
    int get(int index) {
        if (index>size) return-1;
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
        size++;
    }
    
    void addAtTail(int val) {
        Node* newnode = new Node{val, nullptr};
        if (!head) {
            head = newnode;
            size++;
            return;
        }
        Node* temp = head;
        while (temp->next) temp=temp->next;
        temp->next = newnode;
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
        if (!head) return;

        if (index==0){
            Node* todel = head;
            head = head->next;
            delete todel;
            size--;
            return;
        }

        Node* curr = head;
        for (int i=0;i<index-1 && curr;i++){
            curr = curr->next;
        }
        if (!curr || !curr->next) return;

        Node* todel = curr->next;
        curr->next = curr->next->next;
        size--;
        delete todel;
        return;


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