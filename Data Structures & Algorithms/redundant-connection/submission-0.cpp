class Solution {
public:
    int par[1005];
    int sz[1005];
    int root(int x){
        while(x != par[x]){
            x = par[x];
        }
        return x;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i = 1; i <= edges.size(); i++){
            par[i] = i;
            sz[i] = 1;
        }
        vector<int> ans;
        for(auto& edge:edges){
            int x = root(edge[0]), y = root(edge[1]);
            if(x == y){
                return edge;
            }
            if(sz[x] > sz[y]){
                sz[x] += sz[y];
                par[y] = x;
            }
            else{
                sz[y] += sz[x];
                par[x] = y;
            }
        }
    }
};
