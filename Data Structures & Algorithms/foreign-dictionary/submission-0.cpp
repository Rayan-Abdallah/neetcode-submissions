#include <cstring>
class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        if(words.size() == 1){
            return words[0];
        }
        bool vis[26];
        int indegree[26] = {};
        memset(vis, 0, sizeof(vis));
        for(auto& s: words){
            for(auto& c: s){
                vis[c - 'a'] = true;
            }
        }
        vector<int> cs;
        for(int i = 0; i < 26; i++){
            if(vis[i]){
                cs.push_back(i);
            }
        }
        vector<int> adj[26];
        for(int i = 0; i < words.size() - 1; i++){
            int ind = 0;
            while(ind < words[i].size()
            && ind < words[i+1].size()
            && words[i][ind] == words[i+1][ind]){
                ind++;
            }
            if(ind == words[i+1].size() && ind != words[i].size()){
                return "";
            }
            if(ind == words[i].size()){
                continue;
            }
            adj[words[i][ind] - 'a'].push_back(words[i+1][ind] - 'a');
            indegree[words[i+1][ind] - 'a']++;
        }
        vector<char> ans;
        queue<int> q;
        for(int i = 0; i < cs.size();i++){
            if(indegree[cs[i]] == 0){
                q.push(cs[i]);
            }
        }
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node + 'a');
            q.pop();
            for(int i = 0; i < adj[node].size(); i++){
                indegree[adj[node][i]]--;
                if(!indegree[adj[node][i]]){
                    q.push(adj[node][i]);
                }
            }
        }
        if(ans.size() != cs.size()){
            return "";
        }
        else{
            string res = "";
            for(int i = 0; i < ans.size(); i++){
                res += ans[i];
            }
            return res;
        }
    }
};
