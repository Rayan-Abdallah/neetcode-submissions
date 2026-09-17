class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int dp[100];
        int dist[100][100];
        for(int i = 0; i < n; i++){
            dp[i] = 1000001;
            for(int j = 0; j < n; j++){
                dist[i][j] = 1000001;
            }
        }
        for(auto& flight: flights){
            dist[flight[0]][flight[1]] = flight[2];
        }
        dp[src] = 0;
        for(int i = 0; i < k + 1; i++){
            vector<pair<int, int> > newStops;
            for(int st = 0; st < n; st++){
                for(int en = 0; en < n; en++){
                    if(st != en && dp[st] != 1000001 && dist[st][en] != 1000001){
                        newStops.push_back({en, dp[st] + dist[st][en]});
                    }
                }
            }
            for(auto p: newStops){
                dp[p.first] = min(dp[p.first], p.second);
            }
        }
        if(dp[dst] == 1000001){
            return -1;
        }
        return dp[dst];
    }
};
