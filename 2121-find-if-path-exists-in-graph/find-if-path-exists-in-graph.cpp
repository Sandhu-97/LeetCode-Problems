class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    bool dfs(int node, int dest){
        vis[node] = true;
        if (node == dest) return true;
        for (auto n: adj[node]){
            if (!vis[n]){
                if (dfs(n, dest)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        adj.assign(n, vector<int>());
        vis.assign(n, false);
        for (auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        return dfs(source, destination);
    }
};