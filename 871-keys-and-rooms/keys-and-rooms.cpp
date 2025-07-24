class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size());
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty()){
            int front = q.front();
            q.pop();
            for (auto v: rooms[front]){
                if (!visited[v]) {
                    q.push(v);
                    visited[v]= true;
                }
            }
        }

        for (bool b: visited) if(!b) return false;
        return true;
    }
};