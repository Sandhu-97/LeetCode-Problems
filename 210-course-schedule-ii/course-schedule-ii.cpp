class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adj(V);
        vector<int> ans;
        vector<int> indegree(V);
        queue<int> q;

        for (auto edge: prerequisites){
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        for (int i=0;i<V;i++){
            if (indegree[i]==0) q.push(i);
        }

        while (!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for (auto v: adj[front]){
                indegree[v]--;
                if (indegree[v]==0) {
                    q.push(v);
                }
            }
        }

        if (ans.size()<V) return {};
        return ans; 
    }
};