class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        struct pos{
            int x, y, t;
        };
        queue<pos> q;
        int n = grid.size(), m = grid[0].size();
        std::function<bool(int, int)> valid = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j, 0});
                }
            }
        }
        int res = 0;
        while(!q.empty()){
            pos cur = q.front();
            q.pop();
            res = max(res, cur.t);
            if(valid(cur.x - 1, cur.y) && grid[cur.x - 1][cur.y] == 1){
                grid[cur.x - 1][cur.y] = 2;
                q.push({cur.x - 1, cur.y, cur.t + 1});
            }
            if(valid(cur.x + 1, cur.y) && grid[cur.x + 1][cur.y] == 1){
                grid[cur.x + 1][cur.y] = 2;
                q.push({cur.x + 1, cur.y, cur.t + 1});
            }
            if(valid(cur.x, cur.y - 1) && grid[cur.x][cur.y - 1] == 1){
                grid[cur.x][cur.y - 1] = 2;
                q.push({cur.x, cur.y - 1, cur.t + 1});
            }
            if(valid(cur.x, cur.y + 1) && grid[cur.x][cur.y + 1] == 1){
                grid[cur.x][cur.y + 1] = 2;
                q.push({cur.x, cur.y + 1, cur.t + 1});
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return res;
    }
};
