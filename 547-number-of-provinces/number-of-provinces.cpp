class Solution {
public:
    int count = 0;
    vector<bool> visited;
    void dfs(int node, vector<vector<int>>& mat){
        visited[node] = true;
        
        for (int v=0;v<mat.size();v++){
            if (!visited[v] && mat[node][v]==1) dfs(v, mat);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        visited.assign(v, false);
        
        for (int i=0;i<v;i++){
            if (!visited[i]){
                dfs(i, isConnected);
                count++;
            }
        }

        return count;

    }
};