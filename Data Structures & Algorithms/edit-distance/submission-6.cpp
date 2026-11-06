class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[101][101];

        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                dp[i][j] = 1000000007;
            }
        }

        for(int i = word1.size(); i >= 0; i--){
            for(int j = word2.size(); j >= 0; j--){

                if(i == word1.size() && j == word2.size()){

                    dp[i][j] = 0;

                } else if(i == word1.size()){

                    dp[i][j] = word2.size() - j;

                } else if(j == word2.size()){

                    dp[i][j] = word1.size() - i;

                } else {

                    if(word1[i] == word2[j]) {
                        dp[i][j] = min(dp[i][j], dp[i + 1][j + 1]);
                    }

                    dp[i][j] = min(dp[i][j], min(1 + dp[i + 1][j], 
                    min(1 + dp[i + 1][j + 1], 1 + dp[i][j + 1])));
                }
            }
        }
        return dp[0][0];
    }
};
