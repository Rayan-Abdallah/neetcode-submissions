class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        bool dpl[105][105] = {0}, dpr[105][105] = {0};
        bool visl[105][105] = {0}, visr[105][105] = {0};
        int n = heights.size(), m = heights[0].size();
        for(int i = 0; i < m; i++){
            dpl[0][i] = 1;
            dpr[n - 1][i] = 1;
        }
        for(int i = 0; i < n; i++){
            dpl[i][0] = 1;
            dpr[i][m - 1] = 1;
        }
        auto inLim = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        std::function<void(int, int)> dfs;
        std::function<void(int, int)> dfs2;
        dfs = [&](int x, int y){
            if(visl[x][y]){
                return;
            }
            dpl[x][y] = 1;
            visl[x][y] = 1;
            if(inLim(x - 1, y) && heights[x - 1][y] >= heights[x][y]){
                dfs(x - 1, y);
            }
            if(inLim(x + 1, y) && heights[x + 1][y] >= heights[x][y]){
                dfs(x + 1, y);
            }
            if(inLim(x, y - 1) && heights[x][y - 1] >= heights[x][y]){
                dfs(x, y - 1);
            }
            if(inLim(x, y + 1) && heights[x][y + 1] >= heights[x][y]){
                dfs(x, y + 1);
            }
        };
        dfs2 = [&](int x, int y){
            if(visr[x][y]){
                return;
            }
            dpr[x][y] = 1;
            visr[x][y] = 1;
            if(inLim(x - 1, y) && heights[x - 1][y] >= heights[x][y]){
                dfs2(x - 1, y);
            }
            if(inLim(x + 1, y) && heights[x + 1][y] >= heights[x][y]){
                dfs2(x + 1, y);
            }
            if(inLim(x, y - 1) && heights[x][y - 1] >= heights[x][y]){
                dfs2(x, y - 1);
            }
            if(inLim(x, y + 1) && heights[x][y + 1] >= heights[x][y]){
                dfs2(x, y + 1);
            }
        };
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visl[i][j] && dpl[i][j]){
                    dfs(i, j);
                }
                if(!visr[i][j] && dpr[i][j]){
                    dfs2(i, j);
                }
            }
        }
        vector<vector<int> > ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dpl[i][j] && dpr[i][j]){
                    vector<int> coOrds{i, j};
                    ans.push_back(coOrds);
                }
            }
        }
        return ans;
    }
};
