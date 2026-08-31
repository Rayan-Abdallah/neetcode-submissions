class Solution {
public:
    int n, m;
    bool valid(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        int res = 0;
        if(valid(x + 1, y) && matrix[x+1][y] > matrix[x][y]){
            res = max(res, dfs(x + 1, y, matrix, dp) + 1);
        }
        if(valid(x - 1, y) && matrix[x-1][y] > matrix[x][y]){
            res = max(res, dfs(x - 1, y, matrix, dp) + 1);
        }
        if(valid(x, y - 1) && matrix[x][y - 1] > matrix[x][y]){
            res = max(res, dfs(x, y - 1, matrix, dp) + 1);
        }
        if(valid(x, y + 1) && matrix[x][y+1] > matrix[x][y]){
            res = max(res, dfs(x, y + 1, matrix, dp) + 1);
        }
        dp[x][y] = res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> dp;
        for(int i = 0; i < n; i++){
            vector<int> row(m, -1);
            dp.push_back(row);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, dfs(i, j, matrix, dp) + 1);
            }
        }
        return ans;
    }
};
