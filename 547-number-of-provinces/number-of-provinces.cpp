class UF{
    public:
    vector<int> parent, rank;

    UF(int n){
        parent.resize(n);
        rank.assign(n ,0);
        for (int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int find (int n){
        if (parent[n]!=n) {
            return parent[n]=find(parent[n]);
        }
        return parent[n];
    }

    void unite(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if (pa==pb) return;

        if (rank[pa]>rank[pb]){
            parent[pb] = pa;
        }
        else if (rank[pa]<rank[pb]){
            parent[pa] = pb;
        }
        else{
            parent[pb] = pa;
             rank[pa]++;
        }
    }
    int ans(int n){
        int count=0;
        for (int i=0;i<n;i++){
            if (parent[i]==i) count++;
        }
        return count;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& conn) {
        int n = conn.size();
        UF uf(n);

        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                if (conn[i][j]==1) uf.unite(i, j);
            }
        }

        return uf.ans(n);

    }
};