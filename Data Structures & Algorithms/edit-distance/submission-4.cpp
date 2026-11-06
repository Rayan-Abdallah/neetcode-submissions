class Solution {
    int dp[101][101];
    bool vis[101][101];
    int recDp(int i, int j, string& word1, string& word2) {
        if(i == word1.size() && j == word2.size()){
            return 0;
        }
        if(vis[i][j]){
            return dp[i][j];
        }
        if(i == word1.size()){
            dp[i][j] = word2.size() - j;
        } else if(j == word2.size()){
            dp[i][j] = word1.size() - i;
        } else {
            if(word1[i] == word2[j]) {
                dp[i][j] = min(dp[i][j], recDp(i + 1, j + 1, word1, word2));
            }
            dp[i][j] = min(dp[i][j], 
            min(1 + recDp(i + 1, j, word1, word2), 
            min(1 + recDp(i + 1, j + 1, word1, word2), 
            1 + recDp(i, j + 1, word1, word2))));
        }
        vis[i][j] = 1;
        return dp[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                dp[i][j] = 10000007;
                vis[i][j] = 0;
            }
        }
        return recDp(0, 0, word1, word2);
    }
};
