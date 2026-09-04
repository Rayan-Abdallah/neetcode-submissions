class Solution {
private:
    int n, m;
    bool valid(int x, int y){
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    int dfs(bool (&vis)[50][50], int x, int y, vector<vector<int>>& grid){
        if(!valid(x, y) || grid[x][y] == 0){
            return 0;
        }
        if(vis[x][y]){
            return 0;
        }
        int ans = 1;
        vis[x][y] = 1;
        ans += dfs(vis, x + 1, y, grid);
        ans += dfs(vis, x - 1, y, grid);
        ans += dfs(vis, x, y + 1, grid);
        ans += dfs(vis, x, y - 1, grid);
        return ans;
    }
public:

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        bool vis[50][50] = {0};
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, dfs(vis, i, j, grid));
            }
        }
        return ans;
    }
};
