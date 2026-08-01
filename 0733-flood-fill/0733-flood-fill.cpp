class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        int val = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        vis[sr][sc] = 1;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int desr[] = {0, -1, 1, 0};
            int desc[] = {-1, 0, 0, 1};
            for(int i = 0; i < 4; i++){
                int nsr = row + desr[i];
                int nsc = col + desc[i];
                if(nsr >=0 && nsr < n && nsc >= 0 && nsc < m
                    && !vis[nsr][nsc] && image[nsr][nsc] == val){
                        q.push({nsr, nsc});
                        vis[nsr][nsc] = 1;
                        image[nsr][nsc] = color;
                    }
            }
        }
        return image;
    }
};