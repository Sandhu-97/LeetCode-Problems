class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row, col;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                } 
            }
        }

        for (int i: row){
            for (int c=0;c<n;c++) matrix[i][c]=0;
        }
        for (int i: col){
            for (int r=0;r<m;r++) matrix[r][i]=0;
        }
    }
};