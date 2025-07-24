class Solution {
public:

    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited){
        if (visited[u]) return;
        visited[u] = true;

        for (auto v: adj[u]){
            if (!visited[v]) dfs(v, adj, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (i==j) continue;
                if (isConnected[i][j]==1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n);
        int count=0;

        for (int i=0;i<n;i++){
            if (!visited[i]) {
                dfs(i, adj, visited);
                count++;
            }
        }
        return count;
    }
};