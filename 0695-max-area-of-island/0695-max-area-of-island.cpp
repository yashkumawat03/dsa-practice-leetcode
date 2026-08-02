class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col){
        vis[row][col] = 1;
        int delrow[] = {0, -1, 1, 0};
        int delcol[] = {-1, 0, 0, 1};
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 1;
        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    cnt += dfs(grid, vis, nrow, ncol);
            }
        }
        return cnt;
     }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int maxi = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == 1){
                    int val = dfs(grid, vis, row, col);
                    maxi = max(val, maxi);
                }
            }
        }
        return maxi;
    }
};