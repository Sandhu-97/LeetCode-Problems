class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0, rotten=0, empty=0;
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {1,-1,0,0};

        queue<pair<int,int>> q;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                int cur = grid[i][j];
                if (cur==0) empty++;
                else if (cur==1) fresh++;
                else{
                    rotten++;
                    q.push({i,j});
                }
            }
        }
        int time = 0;
        while (!q.empty()){
            int size = q.size();
            while (size--){
                auto [i,j] = q.front(); q.pop();
                for (int k=0;k<4;k++){
                    int newi = i+dx[k];
                    int newj = j+dy[k];

                    if (newi<0 || newj<0 || newi>=m || newj >= n || grid[newi][newj]!=1) continue;
                    q.push({newi, newj});
                    grid[newi][newj] = 2;
                    fresh--;
                }
            }
            if (!q.empty()) time++;
        }
        return fresh==0 ? time : -1;
    }
};