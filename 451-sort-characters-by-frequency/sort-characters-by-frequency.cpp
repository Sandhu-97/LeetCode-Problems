class Solution {
public:
    string frequencySort(string s) {
	unordered_map<char, int> mp;
    priority_queue<pair<int, char>> pq;

	for (char c: s){
		mp[c]++;
	}

	for (auto i: mp){
        pq.push({i.second, i.first});
    }

    string res="";
    while (!pq.empty()){
        auto i = pq.top();
        pq.pop();
        res.append(i.first, i.second);
    }

	return res;
    }
};