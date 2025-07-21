class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i: nums) mp[i]++;
        

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (auto i: mp){
            pq.push({i.second, i.first});
            if (pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};