class TrieNode{
    public:
    bool end;
    int val;
    TrieNode* children[26];
    TrieNode(){
        end=false;
        val=-1;
        for (auto& c: children) c = nullptr;
    }
};
class MapSum {
public:
    TrieNode* root;
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* curr = root;
        for (char c: key){
            int idx = c-'a';
            if (curr->children[idx]==nullptr){
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->end = true;
        curr->val = val;
    }
    void dfs(TrieNode* node, int& ans){
        if (!node) return;

        for (auto n: node->children){
            if (!n) continue;
            if (n->end){
                ans += n->val;
            }
            dfs(n, ans);
        }
    }
    int sum(string prefix) {
        TrieNode* curr = root;
        int ans = 0;
        for (char c: prefix){
            int idx = c-'a';
            if (curr->children[idx]==nullptr) return 0;
            curr = curr->children[idx];
        }
        if (curr->end) ans+=curr->val;
        dfs(curr, ans);
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */