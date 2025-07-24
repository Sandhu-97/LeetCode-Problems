class Solution {
public:

    void dfs(int u, vector<vector<int>>& isConnected, vector<bool>& visited){
        if (visited[u]) return;
        visited[u] = true;

        for (int v=0;v<isConnected.size();v++){
            if (!visited[v] && isConnected[u][v]==1) dfs(v, isConnected, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();


        vector<bool> visited(n);
        int count=0;

        for (int i=0;i<n;i++){
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                count++;
            }
        }
        return count;
    }
};