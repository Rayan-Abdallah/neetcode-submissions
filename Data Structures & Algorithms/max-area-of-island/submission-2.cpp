class Solution {
private:
    pair<int, int> par[50][50];
    int sz[50][50] = {0};
    pair<int, int> findRoot(pair<int, int> x){
        while(x != par[x.first][x.second]){
            x = par[x.first][x.second];
        }
        return x;
    }
    void joinTrees(pair<int, int> x, pair<int, int> y){
        x = findRoot(x), y = findRoot(y);
        if(x == y){
            return;
        }
        if(sz[x.first][x.second] > sz[y.first][y.second]){
            sz[x.first][x.second] += sz[y.first][y.second];
            par[y.first][y.second] = x;
        }
        else{
            sz[y.first][y.second] += sz[x.first][x.second];
            par[x.first][x.second] = y;
        }
    }
public:

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                par[i][j] = {i, j};
                sz[i][j] = grid[i][j];
            }
        }
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(grid[i][0] != 0 && grid[i - 1][0] != 0){
                joinTrees({i, 0}, {i - 1, 0});
            }
        }
        for(int i = 1; i < m; i++){
            if(grid[0][i] != 0 && grid[0][i - 1] != 0){
                joinTrees({0, i}, {0, i - 1});
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(grid[i][j] != 0){
                    if(grid[i - 1][j] != 0){
                        joinTrees({i, j}, {i - 1, j});
                    }
                    if(grid[i][j - 1] != 0){
                        joinTrees({i, j}, {i, j - 1});
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, sz[i][j]);
            }
        }
        return ans;
    }
};
