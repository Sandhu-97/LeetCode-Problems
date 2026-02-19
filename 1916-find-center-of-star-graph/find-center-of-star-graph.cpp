class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;

        for (auto edge: edges){
            int u = edge[0], v =edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        int n = mp.size();
        for (auto it: mp){
            if (it.second.size()>=n-1) return it.first;
        }
        return -1;
    }
};