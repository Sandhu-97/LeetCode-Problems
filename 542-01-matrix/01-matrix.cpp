class Solution {
public:


    int rows, cols;

    bool isSafe(int row, int col, vector<vector<int>>& mat){
        return row>=0 && col>=0 && row<rows && col < cols && mat[row][col]!=0;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        rows = mat.size();
        cols = mat[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false)); 
        queue<pair<int, int>> q;

        for (int i=0;i<rows;i++){
            for (int j=0;j<cols;j++){
                if (mat[i][j]==0){
                    visited[i][j]=true;
                    q.push({i,j});
                }
            }
        }

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        while (!q.empty()){
            int size=q.size();

            for (int i=0;i<size;i++){
                auto front = q.front();
                q.pop();

                int row = front.first;
                int col = front.second;

                for (int i=0;i<4;i++){
                    int newrow = row+dx[i];
                    int newcol = col+dy[i];

                    if (isSafe(newrow, newcol, mat) && !visited[newrow][newcol]){
                        q.push({newrow, newcol});
                        visited[newrow][newcol] = true;
                        mat[newrow][newcol] = mat[row][col] + 1;
                    }
                }
            }
        }
        return mat;
         
    }
};