class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inorder(numCourses, 0);
        for (auto edge: prerequisites){
            adj[edge[0]].push_back(edge[1]);
            inorder[edge[1]]++;
        }
        queue<int> q;
        for (int i=0;i<numCourses;i++){
            if (inorder[i]==0) q.push(i);
        }
        int count=0;
        while (!q.empty()){
            int front = q.front(); q.pop();
            count++;
            for (int neigh: adj[front]){
                inorder[neigh]--;
                if (inorder[neigh]==0) q.push(neigh);
            }

        }
        return count==numCourses;


    }
};