class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> to_routes;
        for (int i=0;i<routes.size();i++){
            for (int j: routes[i]){
                to_routes[j].push_back(i);
            }
        }
        queue<pair<int,int>> q;
        unordered_set<int> st = {source};
        q.push({source, 0});

        while(!q.empty()){
            auto [stop, bus] = q.front(); q.pop();
            if (stop==target) return bus;
            for (int i: to_routes[stop]){
                for (int j: routes[i]){
                    if (st.find(j)==st.end()){
                        st.insert(j);
                        q.push({j, bus+1});
                    }
                }
                routes[i].clear();
            }
        }
        return -1;

    }
};