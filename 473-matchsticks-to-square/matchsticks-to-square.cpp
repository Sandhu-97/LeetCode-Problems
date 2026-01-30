class Solution {
public:
    int target;
    bool solve(int i, vector<int>& sticks, vector<int>& sides){
        if (i>=sticks.size()) return true;
        for (int j=0;j<4;j++){
            if (sides[j]+sticks[i]>target) continue;
            sides[j] += sticks[i];
            if (solve(i+1, sticks, sides)) return true;
            sides[j] -= sticks[i];

            if (sides[j]==0) break; 
        }
        return false;
    }
    bool makesquare(vector<int>& sticks) {
        int sum = accumulate(sticks.begin(), sticks.end(), 0);
        if (sum%4!=0) return false;
        target = sum/4;
        sort(sticks.rbegin(), sticks.rend());
        vector<int> sides(4, 0);
        return solve(0, sticks, sides);
    }
};