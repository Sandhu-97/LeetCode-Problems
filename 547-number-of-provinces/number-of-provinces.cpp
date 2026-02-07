class Solution {
public:
    queue<int> q;
    void bfs(int node, vector<vector<int>>& mat, vector<bool>& visited){
        q.push(node);
        visited[node] = true;

        while (!q.empty()){
            int front = q.front();
            q.pop();

            for (int v=0;v<mat.size();v++){
                if(mat[front][v]==1 && !visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        } 
    }
    int findCircleNum(vector<vector<int>>& mat) {
        int v = mat.size();
        vector<bool> vis(v, false);
        int count=0;
        for(int i=0;i<mat.size();i++){
            if (!vis[i]){
                bfs(i, mat, vis);
                count++;
            }
        }
        return count;
    }
};