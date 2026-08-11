class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> dp;
        unordered_map<string, bool> vis;
        for(auto& word: wordDict){
            dp[word] = true;
            vis[word] = true;
        }
        vis[""] = true;
        dp[""] = true;
        std::function<bool(string&)> rec;
        rec = [&](string& cur){
            if(vis[cur]){
                return dp[cur];
            }
            vis[cur] = true;
            string acc = "";
            for(int i = 0; i < cur.size(); i++){
                acc += cur[i];
                if(dp[acc]){
                    string rest = "";
                    for(int j = i + 1; j < cur.size(); j++){
                        rest += cur[j];
                    }
                    if(rec(rest)){
                        dp[cur] = true;
                        return true;
                    }
                }
            }
            return false;
        };
        return rec(s);
    }
};
