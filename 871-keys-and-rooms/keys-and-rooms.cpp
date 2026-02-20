class Solution {
public:
    vector<bool> visited;

    void dfs(int i, vector<vector<int>>& rooms){
        visited[i] = true;

        for (auto neigh: rooms[i]){
            if (!visited[neigh]){
                dfs(neigh, rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        visited.assign(n, false);
        dfs(0, rooms);

        for (bool v: visited){
            if (!v) return v;
        }
        return true;

    }
};