class Solution {
public:

    static bool comp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n==1) return intervals;
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> res;

        for (int i=0;i<n;i++){
            if(res.empty() || res.back()[1] < intervals[i][0]){
                res.push_back(intervals[i]);
            }
            else if (intervals[i][0] <= res.back()[1]){
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;

    }
};