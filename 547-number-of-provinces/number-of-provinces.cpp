class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if (parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int a, int b){
        int pa=find(a), pb = find(b);
        if (pa==pb) return;
        if (rank[pa]>rank[pb]) parent[pb]=pa;
        else if (rank[pb]>rank[pa]) parent[pa]=pb;
        else{
            parent[pb]=pa;
            rank[pa]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        rank.resize(n, 0);
        parent.resize(n);
        for (int i=0;i<n;i++) parent[i]=i;

        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (isConnected[i][j]==1) unite(i, j);
            }
        }

        int ans=0;
        for (int i=0;i<n;i++){
            if (parent[i]==i) ans++;
        }
        return ans;
    }
};