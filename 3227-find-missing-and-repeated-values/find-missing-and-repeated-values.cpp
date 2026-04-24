class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n= grid.size();
        vector<int> mp(n*n+1, 0);
        for (auto arr: grid){
            for (auto i: arr) mp[i]++;
        }
        int ans1=0, ans2=0;
        for (int i=1;i<=n*n;i++){
            if (mp[i]>1){
                ans1=i;
            }
            if (mp[i]==0) ans2=i;
        }
        return {ans1, ans2};
    }
};