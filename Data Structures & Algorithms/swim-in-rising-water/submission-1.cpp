class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        queue<pair<int, int> > bfs;
        int waterLvl = grid[0][0] - 1;
        int n = grid.size();
        if(n == 1){
            return grid[0][0];
        }
        vector<vector<bool> > vis(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                vis[i].push_back(0);
            }
        }
        auto valid = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < n;
        };
        vis[0][0] = 1;
        while(!vis[n-1][n-1]){
            waterLvl++;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(vis[i][j]){
                        bfs.push({i, j});
                    }
                }
            }
            while(!bfs.empty()){
                pair<int,int> p = bfs.front();
                bfs.pop();
                int x = p.first, y = p.second;
                if(valid(x + 1, y) && !vis[x + 1][y] && grid[x + 1][y] <= waterLvl){
                    vis[x + 1][y] = 1;
                    bfs.push({x + 1, y});
                }
                if(valid(x - 1, y) && !vis[x - 1][y] && grid[x - 1][y] <= waterLvl){
                    vis[x - 1][y] = 1;
                    bfs.push({x - 1, y});
                }
                if(valid(x, y + 1) && !vis[x][y + 1] && grid[x][y + 1] <= waterLvl){
                    vis[x][y + 1] = 1;
                    bfs.push({x, y + 1});
                }
                if(valid(x, y - 1) && !vis[x][y - 1] && grid[x][y - 1] <= waterLvl){
                    vis[x][y - 1] = 1;
                    bfs.push({x, y - 1});
                }
            }
        }
        return waterLvl;
    }
};
