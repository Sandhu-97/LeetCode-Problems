class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if (parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b){
        int para=find(a);
        int parb=find(b);
        if (para==parb) return;

        if (rank[para]>rank[parb]) parent[parb]=para;
        else if (rank[para]<rank[parb]) parent[para]=parb;
        else {
            parent[para]=parb;
            rank[parb]++;
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
            if (i==parent[i]) count++;
        }
        return count-1;
    }
};