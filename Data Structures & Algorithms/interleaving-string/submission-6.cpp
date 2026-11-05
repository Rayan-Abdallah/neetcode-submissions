class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size()){
            return false;
        }
        bool dp[101][101];
        for(int i = 0; i < 101; i++){
            for(int j = 0; j < 101; j++){
                dp[i][j] = 0;
            }
        }

        for(int i = s1.size(); i >= 0; i--){
            for(int j = s2.size(); j >= 0; j--){
                if(i == s1.size() && j == s2.size()){
                    dp[i][j] = true;
                }
                else if(i == s1.size()){
                    if(s2[j] == s3[i + j]){
                        dp[i][j] |= dp[i][j + 1];
                    }
                } else if (j == s2.size()) {
                    if(s1[i] == s3[i + j]){
                        dp[i][j] |= dp[i + 1][j];
                    }
                } else {
                    if(s1[i] == s3[i + j]){
                        dp[i][j] |= dp[i + 1][j];
                    }
                    if(s2[j] == s3[i + j]){
                        dp[i][j] |= dp[i][j + 1];
                    }
                }
            }
        }
        return dp[0][0];
    }
};
