class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        ans.push_back({1});
        if (numRows<=1) return ans;
        ans.push_back({1, 1});
        if (numRows<=2) return ans;

        int count = 3;
        for (int i=2;i<numRows;i++){
            vector<int> temp;
            for (int j=0;j<count;j++){
                if (j==0 || j==count-1) temp.push_back(1);
                else {
                    temp.push_back(ans[i-1][j-1]+ans[i-1][j]);
                }
            }

            ans.push_back(temp);
            count++;
        }

        return ans;


    }
};