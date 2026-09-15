class Solution {
public:
    vector<int> visited;

    bool cycle(int i, int parent, vector<vector<int>>& adj){
        visited[i]=1;
        for (auto neigh: adj[i]){
            if (visited[neigh]==1) return true;
            else if (visited[neigh]==0){
                if (cycle(neigh, i, adj)) return true;
            }
        }
        visited[i]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto edge: prerequisites){
            adj[edge[0]].push_back(edge[1]);
        }
        visited.resize(numCourses,0);

        for (int i=0;i<numCourses;i++){
            if (visited[i]==0){
                if (cycle(i, -1, adj)) return false;
            }
        }
        return true;


    }
};