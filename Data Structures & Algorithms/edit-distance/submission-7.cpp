class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> dp, newDp;

        for(int i = 0; i <= word2.size(); i++){
            dp.push_back(1000000007);
            newDp.push_back(1000000007);
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

                    if(word1[i] == word2[j]) {
                        newDp[j] = dp[j + 1];
                    } else {
                        newDp[j] = 1000000007;
                    }

                    newDp[j] = min(newDp[j], min(1 + dp[j], 
                    min(1 + dp[j + 1], 1 + newDp[j + 1])));
                }
            }
            dp = newDp;
        }
        return newDp[0];
    }
};
