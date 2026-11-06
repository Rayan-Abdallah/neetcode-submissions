class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> dp(102), newDp(102);

        for(int i = 0; i <= word2.size(); i++){
            dp[i] = 1000000007;
            newDp[i] = 1000000007;
        }

        for(int i = word1.size(); i >= 0; i--){
            for(int j = word2.size(); j >= 0; j--){
                if(i == word1.size() && j == word2.size()){

                    newDp[j] = 0;

                } else if(i == word1.size()){

                    newDp[j] = word2.size() - j;

                } else if(j == word2.size()){

                    newDp[j] = word1.size() - i;

                } else {
                    newDp[j] = 100000007;
                    if(word1[i] == word2[j]) {
                        newDp[j] = dp[j + 1];
                    } else {
                        newDp[j] = 1 + min(dp[j], min(dp[j + 1], newDp[j + 1]));
                    }
                }
            }
            dp = newDp;
        }
        return newDp[0];
    }
};
