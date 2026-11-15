class Solution {

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> dp;
        unordered_map<string, bool> vis;
        queue<pair<string, int> > bfs;
        bfs.push({beginWord, 1});
        dp[beginWord] = 1;
        vis[beginWord] = true;
        while(!bfs.empty()){
            pair<string, int> p = bfs.front();
            int dst = p.second;
            string cur = p.first;
            bfs.pop();
            for(int i = 0; i < wordList.size(); i++){
                if(vis[wordList[i]]){
                    continue;
                }
                int diff = 0;
                for(int j = 0; j < cur.size(); j++){
                    if(cur[j] != wordList[i][j]){
                        diff++;
                    }
                }
                if(diff != 1){
                    continue;
                }
                bfs.push({wordList[i], dst + 1});
                vis[wordList[i]] = 1;
                dp[wordList[i]] = dst + 1;
            }
        }
        return dp[endWord];
    }
};
