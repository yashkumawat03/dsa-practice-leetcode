class Solution {
public:
    //int maxi = 0;
    int bfs(vector<vector<int>>& grid, vector<vector<int>>&vis, int row, int col){
        queue<pair<int, int>> q;
        vis[row][col] = 1;
        q.push({row, col});
        int cnt = 1;
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int delrow[] = {0, -1, 0, 1};
            int delcol[] = {-1, 0, 1, 0};
            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow< n && ncol >= 0 && ncol < m
                    && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                        cnt++;
                }
            }
        }
        return cnt;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        vector<vector<int>> vis(n, vector<int>(m));
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == 1 && !vis[row][col]){
                    int val =  bfs(grid, vis, row, col);
                    maxi = max(maxi, val);
                }
            }
        }
        return maxi;
    }
};