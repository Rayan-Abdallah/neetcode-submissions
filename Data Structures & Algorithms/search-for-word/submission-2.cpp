class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(word[0] == board[i][j]){
                    bool vis[5][5] = {0};
                    auto check = [&](int l, int r){
                        if(l >= 0 && l < board.size() && r >= 0 && r < board[i].size()){
                            return true;
                        }
                        return false;
                    };
                    std::function<void(int, int, bool[5][5], string)> dfs;
                    dfs = [&](int l, int r, bool curVis[5][5], string curWord){
                        if(!check(l, r)){
                            return;
                        }
                        if(curVis[l][r]){
                            return;
                        }
                        curWord += board[l][r];
                        curVis[l][r] = 1;
                        if(word.size() == curWord.size()){
                            for(int k = 0; k < word.size(); k++){
                                if(word[k] != curWord[k]){
                                    curVis[l][r] = 0;
                                    return;
                                }
                            }
                            ans = true;
                            curVis[l][r] = 0;
                            return;
                        }
                        for(int k = 0; k < curWord.size(); k++){
                            if(word[k] != curWord[k]){
                                curVis[l][r] = 0;
                                return;
                            }
                        }
                        dfs(l, r + 1, curVis, curWord);
                        dfs(l, r - 1, curVis, curWord);
                        dfs(l + 1, r, curVis, curWord);
                        dfs(l - 1, r, curVis, curWord);
                        curVis[l][r] = 0;
                    };
                    dfs(i, j, vis, "");
                    if(ans){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
