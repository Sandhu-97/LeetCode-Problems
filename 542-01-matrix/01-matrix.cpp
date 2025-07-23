class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for(int i=0;i<rows;i++){
            for (int j=0;j<cols;j++){
                if (mat[i][j]==0) {
                    q.push({i, j});
                    visited[i][j]=true;
                }
            }
        }

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while (!q.empty()){

            auto front = q.front();
            q.pop();
            int row = front.first;
            int col = front.second;
            for (int i=0;i<4;i++){
                int newrow = row+dx[i];
                int newcol = col+dy[i];
                if (newrow>=0 && newrow < rows && newcol>=0 && newcol<cols && !visited[newrow][newcol] && mat[newrow][newcol]!=0){
                    q.push({newrow, newcol});
                    visited[newrow][newcol] = true;
                    mat[newrow][newcol] = mat[row][col]+1;
                }
            }
            
        }
        return mat;
    }
};