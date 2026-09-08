class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int> > q;
        int n = grid.size(), m = grid[0].size();
        std::function<bool(int, int)> valid = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            pair<int, int> pos = q.front();
            q.pop();
            int x = pos.first, y = pos.second;
            if(valid(x - 1, y) && grid[x - 1][y] == 2147483647){
                grid[x - 1][y] = grid[x][y] + 1;
                q.push({x - 1, y});
            }
            if(valid(x + 1, y) && grid[x + 1][y] == 2147483647){
                grid[x + 1][y] = grid[x][y] + 1;
                q.push({x + 1, y});
            }
            if(valid(x, y - 1) && grid[x][y - 1] == 2147483647){
                grid[x][y - 1] = grid[x][y] + 1;
                q.push({x, y - 1});
            }
            if(valid(x, y + 1) && grid[x][y + 1] == 2147483647){
                grid[x][y + 1] = grid[x][y] + 1;
                q.push({x, y + 1});
            }
        }
    }
};
