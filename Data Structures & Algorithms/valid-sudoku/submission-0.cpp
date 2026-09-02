class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            bool visRow[10] = {0};
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == '.'){
                    continue;
                }
                int v = board[i][j] - '1';
                if(visRow[v]){
                    return false;
                }
                visRow[v] = true;
            }
        }
        for(int i = 0; i < board[0].size(); i++){
            bool visCol[10] = {0};
            for(int j = 0; j < board.size(); j++){
                if(board[j][i] == '.'){
                    continue;
                }
                int v = board[j][i] - '1';
                if(visCol[v]){
                    return false;
                }
                visCol[v] = true;
            }
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                bool vis[10] = {0};
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        if(board[i*3 + k][j*3 + l] == '.'){
                            continue;
                        }
                        int v = board[i*3 + k][j*3 + l] - '1';
                        if(vis[v]){
                            return false;
                        }
                        vis[v] = true;
                    }
                }
            }
        }
        return true;
    }
};
