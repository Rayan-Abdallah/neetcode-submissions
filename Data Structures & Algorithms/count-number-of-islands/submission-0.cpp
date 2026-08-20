class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int> > bfs;
        int n = grid.size(), m = grid[0].size(), ans = 0;
        auto valid = [&](int x, int y){
            return (x >= 0 && x < n && y >= 0 && y < m);
        };
        bool vis[105][105] = {0};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    bfs.push({i, j});
                    vis[i][j] = 1;
                    ans++;
                    while(!bfs.empty()){
                        pair cur = bfs.front();
                        int x = cur.first, y = cur.second;
                        bfs.pop();
                        if(valid(x - 1, y) && !vis[x - 1][y] && grid[x - 1][y] == '1'){
                            bfs.push({x - 1, y});
                            vis[x - 1][y] = 1;
                        }
                        if(valid(x, y - 1) && !vis[x][y - 1] && grid[x][y - 1] == '1'){
                            bfs.push({x, y - 1});
                            vis[x][y - 1] = 1;
                        }
                        if(valid(x + 1, y) && !vis[x + 1][y] && grid[x + 1][y] == '1'){
                            bfs.push({x + 1, y});
                            vis[x + 1][y] = 1;
                        }
                        if(valid(x, y + 1) && !vis[x][y + 1] && grid[x][y + 1] == '1'){
                            bfs.push({x, y + 1});
                            vis[x][y + 1] = 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
