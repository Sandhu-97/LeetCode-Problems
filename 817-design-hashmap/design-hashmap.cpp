class MyHashMap {
private:
    const static int SIZE = 1000;
    vector<list<pair<int, int>>> table;
    int hash(int key){
        return key%SIZE;
    }
public:
    MyHashMap() {
        table.resize(SIZE);
    }
    
    void put(int key, int value) {
        int h = hash(key);
        for (auto& node: table[h]){
            if (node.first==key){
                node.second=value;
                return;
            }
        }
        table[h].push_back({key, value});
    }
    
    int get(int key) {
        int h = hash(key);
        for (auto node: table[h]){
            if (node.first==key){
                return node.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int h = hash(key);
        auto& bucket = table[h];
        for (auto it=bucket.begin();it!=bucket.end();it++){
            if (it->first==key){
                bucket.erase(it);
                return ;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */