class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses, false);
        vector<int> indegree(numCourses, 0);
        vector<int> ans;
        queue<int> q;

        for (auto edge: prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i=0;i<numCourses;i++){
            for (auto v: adj[i]){
                indegree[v]++;
            }
        }

        for (int i=0;i<numCourses;i++) {
            if (indegree[i]==0) {
                q.push(i);
                visited[i] = true;
            }
        }


        while (!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for (auto v: adj[front]){
                indegree[v]--;
                if (indegree[v]==0) q.push(v);
            }
        }

        return ans.size()==numCourses;
        
    }
};