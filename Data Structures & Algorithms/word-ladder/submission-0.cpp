class Solution {
    int rec(string curWord, string endWord, vector<string>& wordList, unordered_map<string, int>& dp, unordered_map<string, bool>& vis){
        if(curWord == endWord){
            return 1;
        }
        vis[curWord] = true;
        dp[curWord] = wordList.size() + 100;
        for(int i = 0; i < wordList.size(); i++){
            int difCnt = 0;
            for(int j = 0; j < curWord.size(); j++){
                if(curWord[j] != wordList[i][j]){
                    difCnt++;
                }
            }
            if(difCnt != 1){
                continue;
            }
            if(vis[wordList[i]]){
                dp[curWord] = min(dp[curWord], 1 + dp[wordList[i]]);
            } else {
                dp[curWord] = min(dp[curWord], 1 + rec(wordList[i], endWord, wordList, dp, vis));
            }
        }
        return dp[curWord];
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> dp;
        unordered_map<string, bool> vis;
        int res = rec(beginWord, endWord, wordList, dp, vis);
        if(res >= wordList.size() + 100){
            return 0;
        }
        return res;
    }
};
