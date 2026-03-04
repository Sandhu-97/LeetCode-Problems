class Solution {
public:
    int m,n;
    bool valid (int row, int col, vector<vector<int>>& mat){
        for (int i=0;i<m;i++){
            if (i==row) continue;
            if (mat[i][col]==1) return false;   
        }

        for (int j=0;j<n;j++){
            if (j==col) continue;
            if (mat[row][j]==1) return false;
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        m=mat.size();
        n=mat[0].size();
        int count=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (mat[i][j]==1 && valid(i,j, mat)) count++;
            }
        }
        return count;
    }
};