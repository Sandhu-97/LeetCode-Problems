class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;

        int count=0;

        for (auto edge: prerequisites){
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        for (int i=0;i<numCourses;i++) {
            if (indegree[i]==0) {
                q.push(i);
            }
        }


        while (!q.empty()){
            int front = q.front();
            q.pop();
            count++;

            for (auto v: adj[front]){
                indegree[v]--;
                if (indegree[v]==0) q.push(v);
            }
        }

        return count==numCourses;
        
    }
};