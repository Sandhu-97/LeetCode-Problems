class Solution {
public:
    vector<int>parent;
    vector<int> rank;

    void unite(int a, int b){
        int parent_a = find(a), parent_b = find(b);
        if (parent_a==parent_b) return;
        if (rank[parent_a]>rank[parent_b]){
            parent[parent_b] = parent_a;
        }
        else if (rank[parent_a]<rank[parent_b]) parent[parent_a] = parent_b;
        else {
            rank[parent_a]++;
            parent[parent_b] = parent_a; 
        }
    }

    int find(int a){
        if (a==parent[a]) return a;
        return parent[a] = find(parent[a]);
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);

        for (int i=0;i<26;i++){
            parent[i]=i;
            rank[i]=0;
        }

        for (string e: equations){
            int u = e[0]-'a', v = e[3]-'a';

            if (e[1]=='='){
                unite(u, v);
            }

        }

        for (string e: equations){
            int u = e[0]-'a', v = e[3]-'a';

            if (e[1]=='!'){
                if (find(u) == find(v)) return false;
            }

        }
        return true;
    }
};