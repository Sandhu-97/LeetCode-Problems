class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> nums;
        for (int i: arr){
            nums.push_back({__builtin_popcount(i), i});
        }
        sort(nums.begin(), nums.end());
        for (int i=0;i<arr.size();i++){
            arr[i] = nums[i].second;
        }
        return arr;
    }
};