class Solution {
bool dp[101][101];
bool vis[101][101];
public:
    bool recDp(int i, int j, string& s1, string& s2, string& s3){
        if(vis[i][j]){
            return dp[i][j];
        }
        if(i == s1.size() && j == s2.size()) {
            vis[i][j] = 1;
            dp[i][j] = true;
            return true;
        }
        else if(i == s1.size()){
            if(s2[j] == s3[i + j]){
                dp[i][j] = recDp(i, j + 1, s1, s2, s3);
            }
        } else if (j == s2.size()) {
            if(s1[i] == s3[i + j]){
                dp[i][j] = recDp(i + 1, j, s1, s2, s3);
            }
        } else {
            if(s1[i] == s3[i + j]){
                dp[i][j] = recDp(i + 1, j, s1, s2, s3);
            }
            if(s2[j] == s3[i + j]){
                dp[i][j] |= recDp(i, j + 1, s1, s2, s3);
            }
        }
        vis[i][j] = true;
        return dp[i][j];
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size()){
            return false;
        }
        for(int i = 0; i < 101; i++){
            for(int j = 0; j < 101; j++){
                dp[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        recDp(0, 0, s1, s2, s3);
        return dp[0][0];
    }
};
