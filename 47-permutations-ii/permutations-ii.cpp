class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    int n;
    unordered_map<int, int> mp;
    void solve(){
        if (curr.size()==n){
            ans.push_back(curr);
            return;
        } 

        for (auto it: mp){
            int num = it.first;
            int count=it.second;
            if (count==0) continue;
            curr.push_back(num);
            mp[num]--;
            solve();
            curr.pop_back();
            mp[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        for (int i: nums) mp[i]++;
        solve();
        return ans;
    }
};