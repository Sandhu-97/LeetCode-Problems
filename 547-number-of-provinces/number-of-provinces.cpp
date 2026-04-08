class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    void unite(int a, int b){
        int parent_a = find(a), parent_b=  find(b);

        if (parent_a==parent_b) return;

        if (rank[parent_a]>rank[parent_b]){
            parent[parent_b] = parent_a;
        } 
        else if (rank[parent_b]>rank[parent_a]){
            parent[parent_a] = parent_b;
        }
        else {
            parent[parent_b] = parent_a;
            rank[parent_a]++;
        }
    }

    int find (int a){
        if (parent[a]==a) return a;
        return parent[a] = find(parent[a]);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        parent.resize(n);
        rank.resize(n);
        for (int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }

        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (isConnected[i][j]) unite(i, j);
            }
        }

        int ans = 0;
        for (int i=0;i<n;i++){
            if (parent[i]==i) ans++;
        }
        return ans;
    }
};