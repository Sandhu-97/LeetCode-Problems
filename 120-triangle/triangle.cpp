class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size()-1;

        for (int row=n-1;row>=0;row--){
            for (int col=0;col<triangle[row].size();col++){
                triangle[row][col] += min(triangle[row+1][col], triangle[row+1][col+1]);
            }
        }
        return triangle[0][0];
    }
};