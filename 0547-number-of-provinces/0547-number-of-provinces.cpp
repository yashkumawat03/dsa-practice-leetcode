class Solution {
public:

    void dfs(vector<vector<int>> &adjL, vector<int> & vis, int i){
        vis[i] = 1;
        for(auto it : adjL[i]){
            if(!vis[it]){
                dfs(adjL, vis, it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjL(n+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1  && i != j){
                    adjL[i + 1].push_back(j + 1);
                    adjL[j + 1].push_back(i + 1);
                }
            }
        }

        int cnt = 0;
        vector<int> vis(n + 1);
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                cnt++;
                dfs(adjL , vis, i);
            }
        }
        return cnt;
    }
};