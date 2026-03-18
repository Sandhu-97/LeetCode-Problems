class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        for (char c: s) mp[c]++;

        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;

        for (auto it: mp){
            pq.push({it.second, it.first});
        }
        s = "";
        while (!pq.empty()){
            auto [freq, c] = pq.top(); pq.pop();
            while (freq--){
                s.push_back(c);
            }
        }

        return s;

    }
};