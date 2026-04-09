class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int a){
        if (a==parent[a]) return a;
        return a = find(parent[a]);
    }

    void unite (int a, int b){
        int pa = find(a);
        int pb = find(b);
        if (pa==pb) return;

        if (rank[pa]>rank[pb]){
            parent[pb] = pa;
        }

        else if (rank[pb]>rank[pa]){
            parent[pa] = pb;
        }

        else {
            parent[pb]=pa;
            rank[pa]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size()<n-1) return -1;

        parent.resize(n);
        rank.resize(n, 0);

        for (int i=0;i<n;i++) parent[i]=i;

        for (auto conn: connections){
            unite(conn[0], conn[1]);
        }

        int count=0;
        for (int i=0;i<n;i++){
            if (parent[i]==i) count++;
        }

        return count-1;
    }
};