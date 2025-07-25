class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adj(n+1);
        for (auto time: times){
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }


        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        vector<int> dist(n+1, INT_MAX);
        dist[k]=0;

        while (!pq.empty()){
            auto top = pq.top();
            int u = top.second;
            int d = top.first;
            pq.pop();

            for (auto vec: adj[u]){
                int v = vec[0];
                int w = vec[1];

                if (dist[v]>w+d) {
                    dist[v] = w+d;
                    pq.push({dist[v], v});
                }
            }
        }

        int maxi = INT_MIN;
        for (int i=1;i<=n;i++) maxi=max(maxi, dist[i]);
        return maxi==INT_MAX? -1 : maxi;

    }
};