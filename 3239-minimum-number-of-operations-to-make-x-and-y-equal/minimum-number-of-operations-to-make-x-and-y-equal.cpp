class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if (x<=y) return y-x;

        int upper = max(x, y) *2;
        vector<bool> visited(upper+1, false);

        queue<pair<int, int>> q;
        q.push({x, 0});
        visited[x] = true;

        while (!q.empty()){
            auto [cur, steps] = q.front();
            q.pop();
            if (cur==y) return steps;

            if (cur-1>=0 && !visited[cur-1]){
                visited[cur-1]=true;
                q.push({cur-1, steps+1});
            }
            if (cur+1<=upper && !visited[cur+1]){
                visited[cur+1] = true;
                q.push({cur+1, steps+1});
            }
            if (cur%5==0){
                int next = cur/5;
                if (next>=0 && !visited[next]){
                    visited[next]=true;
                    q.push({next, steps+1});
                }
            }
            if (cur%11==0){
                int next = cur/11;
                if (next>=0 && !visited[next]){
                    visited[next]=true;
                    q.push({next, steps+1});
                }
            }
        }
        return -1;
    }
};