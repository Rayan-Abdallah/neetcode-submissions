class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int> > dij;
        dij.push({0, k - 1});
        int INF = 0x7FFFFFFF;
        vector<vector<pair<int, int> > > adj(n);
        vector<int> dp(n, INF);
        dp[k - 1] = 0;
        for(auto v: times){
            adj[v[0] - 1].push_back({v[1] - 1, v[2]});
        }
        int ans = 0;
        while(!dij.empty()){
            pair<int, int> p = dij.top();
            dij.pop();
            int t = p.first, ind = p.second;
            dp[ind] = min(t, dp[ind]);
            for(auto path: adj[ind]){
                if(t + path.second < dp[path.first]){
                    dij.push({t + path.second, path.first});
                }
            }
        }
        for(int i = 0; i < n; i++){
            ans = max(ans, dp[i]);
        }
        if(ans == INF){
            return -1;
        }
        return ans;
    }
};
