class Solution {
private:
    int sz;
    int cnt = 0;
    vector<vector<string> > finalRes;
    void backTrack(vector<string>& board, vector<bool>& visCol, vector<vector<bool> >& visDiagonal, int cur){
        if(cur == sz){
            finalRes.push_back(board);
            return;
        }
        int offset;
        for(int j = 0; j < sz; j++){
            offset = sz - cur - 1;
            if(visCol[j] 
            || visDiagonal[0][sz - (cur - j) - 1] 
            || visDiagonal[1][sz - (j - offset) - 1]){
                continue;
            }
            board[cur][j] = 'Q';
            visCol[j] = 1;
            visDiagonal[0][sz - (cur - j) - 1] = 1;
            visDiagonal[1][sz - (j - offset) - 1] = 1;
            backTrack(board, visCol, visDiagonal, cur + 1);
            board[cur][j] = '.';
            visCol[j] = 0;
            visDiagonal[0][sz - (cur - j) - 1] = 0;
            visDiagonal[1][sz - (j - offset) - 1] = 0;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> initialBoard;
        vector<bool> visCol, visRow;
        vector<vector<bool> > visDiagonals(2);
        string empt = "";
        vector<int> emptCnt;
        sz = n;
        for(int i = 0; i < n; i++){
            empt += '.';
            visCol.push_back(0);
            visRow.push_back(0);
            visDiagonals[0].push_back(0);
            visDiagonals[1].push_back(0);
        }
        for(int i = 0; i < n - 1; i++){
            visDiagonals[0].push_back(0);
            visDiagonals[1].push_back(0);
        }
        for(int i = 0; i < n; i++){
            initialBoard.push_back(empt);
        }
        backTrack(initialBoard, visCol, visDiagonals, 0);
        return finalRes;
    }
};
