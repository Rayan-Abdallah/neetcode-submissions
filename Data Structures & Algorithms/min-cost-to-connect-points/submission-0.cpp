class Solution {
private:
    int par[1005];
    int sz[1005];
    int root(int x){
        while(x != par[x]){
            x = par[x];
        }
        return x;
    }
    int dist(vector<int>& l, vector<int>& r){
        return abs(l[0] - r[0]) + abs(l[1] - r[1]);
    }
    bool con(int x, int y){
        x = root(x), y = root(y);
        if(x == y){
            return false;
        }
        if(sz[x] >= sz[y]){
            sz[x] += sz[y];
            par[y] = x;
        }
        else{
            sz[y] += sz[x];
            par[x] = y;
        }
        return true;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        for(int i = 0; i < points.size(); i++){
            par[i] = i;
            sz[i] = 1;
        }
        int ans = 0;
        vector<pair<int, pair<int, int> > > paths;
        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                paths.push_back({dist(points[i], points[j]), {i, j}});
            }
        }
        sort(paths.begin(), paths.end());
        for(auto path: paths){
            if(con(path.second.first, path.second.second)){
                ans += path.first;
            }
        }
        return ans;
    }
};
