class Solution {
public:

    void solve(int u, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& ans){
        path.push_back(u);
        if (u==graph.size()-1){
            ans.push_back(path);
        }

        for (auto neighbor: graph[u]){
            solve(neighbor, graph, path, ans);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;

        solve(0 ,graph, path, ans);
        return ans;


    }
};