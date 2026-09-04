class Solution {
private:
    int n, m;
    bool valid(int x, int y){
        return x >= 0 && y >= 0 && x < n && y < m;
    }
public:

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        bool vis[50][50] = {0};
        int ans = 0;
        queue<pair<int, int> > q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int cur = 0;
                    q.push({i, j});
                    vis[i][j] = 1;
                    while(!q.empty()){
                        pair<int, int> pos = q.front();
                        int x = pos.first, y = pos.second;
                        q.pop();
                        cur++;
                        if(valid(x+1, y) && !vis[x+1][y] && grid[x+1][y]){
                            q.push({x + 1, y});
                            vis[x+1][y] = 1;
                        }
                        if(valid(x-1,y) && !vis[x-1][y] && grid[x-1][y]){
                            q.push({x - 1, y});
                            vis[x-1][y] = 1;
                        }
                        if(valid(x, y+1) && !vis[x][y+1] && grid[x][y+1]){
                            q.push({x, y+1});
                            vis[x][y+1] = 1;
                        }
                        if(valid(x, y-1) && !vis[x][y-1] && grid[x][y-1]){
                            q.push({x, y-1});
                            vis[x][y-1] = 1;
                        }
                    }
                    ans = max(ans, cur);
                }
            }
        }
        return ans;
    }
};
