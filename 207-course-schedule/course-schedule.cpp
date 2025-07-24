class Solution {
public:

    bool isCycleDFS(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& stack){
        visited[u] = true;
        stack[u] = true;

        for (auto v: adj[u]){
            if (!visited[v] && isCycleDFS(v, adj, visited, stack)) return true;
            else if (stack[v]) return true;
        }
        stack[u] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses);
        vector<bool> stack(numCourses);


        for (auto edge: prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i=0;i<numCourses;i++){
            if (!visited[i]){
                if (isCycleDFS(i, adj, visited, stack)) return false;
            }
        }
        return true;
        
    }
};