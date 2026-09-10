#include <cstring>

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int n = board.size(), m = board[0].size();
        bool vis[n][m];
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int> > q;
        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O'){
                q.push({0, i});
                vis[0][i] = 1;
            }
            if(board[n - 1][i] == 'O'){
                q.push({n - 1, i});
                vis[n - 1][i] = 1;
            }
        }
        for(int i = 1; i < n - 1; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if(board[i][m - 1] == 'O'){
                q.push({i, m - 1});
                vis[i][m - 1] = 1;
            }
        }
        std::function<bool(int, int)> valid = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            if(valid(x - 1, y) && board[x - 1][y] == 'O' && !vis[x - 1][y]){
                vis[x - 1][y] = 1;
                q.push({x - 1, y});
            }
            if(valid(x + 1, y) && board[x + 1][y] == 'O' && !vis[x + 1][y]){
                vis[x + 1][y] = 1;
                q.push({x + 1, y});
            }
            if(valid(x, y - 1) && board[x][y - 1] == 'O' && !vis[x][y - 1]){
                vis[x][y - 1] = 1;
                q.push({x, y - 1});
            }
            if(valid(x, y + 1) && board[x][y + 1] == 'O' && !vis[x][y + 1]){
                vis[x][y + 1] = 1;
                q.push({x, y + 1});
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
