class Solution {
public:
    vector<int> rank;
    vector<int> parent;

    void unite(int a, int b){
        if (a==b) return;
        int pa = find(a);
        int pb = find(b);

        if (pa==pb) return;

        if (rank[pa]>rank[pb]) parent[pb]=pa;
        else if (rank[pb]>rank[pa]) parent[pa]=pb;
        else{
            parent[pa]=pb;
            rank[pb]++;
        }
    }
    int find(int a){
        if (parent[a]==a) return a;
        return parent[a]=find(parent[a]);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        rank.resize(n, 0);
        parent.resize(n, 0);
        for (int i=0;i<n;i++) parent[i]=i; 

        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (isConnected[i][j]){
                    unite(i, j);
                }
            }
        }

        int ans = 0;
        for (int i=0;i<n;i++){
            if (parent[i]==i) ans++;
        }

        return ans;
    }

};