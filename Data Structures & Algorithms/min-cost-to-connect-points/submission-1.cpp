class Solution {
private:
    vector<int> mst;
    bool vis[1005];
    int dist[1005];
    int far(vector<int>& l, vector<int>& r){
        return abs(l[0] - r[0]) + abs(l[1] - r[1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        for(int i = 0; i < points.size(); i++){
            vis[i] = 0;
            dist[i] = 0x7FFFFFFF;
        }
        mst.push_back(0);
        dist[0] = 0;
        vis[0] = 1;
        int ans = 0;
        while(mst.size() < points.size()){
            int sm = 0x7FFFFFFF, ind = 0;
            for(int i = 0; i < points.size(); i++){
                if(!vis[i]){
                    dist[i] = min(dist[i], 
                    far(points[mst[mst.size() - 1]], points[i]));
                    if(dist[i] < sm){
                        sm = dist[i];
                        ind = i;
                    }
                }
            }
            mst.push_back(ind);
            vis[ind] = 1;
            ans += dist[ind];
        }
        return ans;
    }
};
