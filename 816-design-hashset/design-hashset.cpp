class MyHashSet {
public:
    const static int size=1000;
    vector<list<int>> table;
    int hash(int key){
        return key%size;
    }
    MyHashSet() {
        table.resize(size);
    }
    
    void add(int key) {
        int h = hash(key);
        auto& bucket = table[h];
        for (int node: bucket) if (node==key) return;
        bucket.push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        auto& bucket = table[h];
        for (auto it=bucket.begin(); it!=bucket.end(); it++){
            if (*it==key ) {
                bucket.erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int h = hash(key);
        auto& bucket = table[h];
        for (int node: bucket){
            if (node==key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */