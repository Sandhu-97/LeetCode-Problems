class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adj(n+1);
        for (auto time: times){
            int u = time[0], v = time[1], w = time[2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        vector<int> ans(n, INT_MAX);
        ans[k-1] = 0;

        while (!pq.empty()){
            auto [dist, node] = pq.top(); pq.pop();
            if (dist>ans[node-1]) continue;
            for (auto neighbor: adj[node]){
                int w = neighbor[1];
                int v = neighbor[0];
                if (dist+w<ans[v-1]){
                    ans[v-1] = dist+w;
                    pq.push({dist+w, v});
                }
            }
        }
        int res = -1;
        for (int i: ans) {
            res = max(res, i);
            if (i==INT_MAX) return -1;
        }
        return res;
        
    }
};