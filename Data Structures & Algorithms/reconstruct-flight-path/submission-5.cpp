class Solution {
    void dfs(unordered_map<string, vector<string> >& options, unordered_map<string, vector<bool> >& vis, vector<string>& res, string& cur){
        for(int i = 0; i < options[cur].size(); i++){
            if(!vis[cur][i]){
                vis[cur][i] = 1;
                dfs(options, vis, res, options[cur][i]);
            }
        }
        res.push_back(cur);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        unordered_map<string, vector<string> > options;
        unordered_map<string, vector<bool> > vis;
        for(auto& v: tickets){
            options[v[0]].push_back(v[1]);
            vis[v[0]].push_back(0);
        }
        vector<string> res;
        string cur = "JFK";
        dfs(options, vis, res, cur);
        reverse(res.begin(), res.end());
        return res;
    }
};
