class Solution {
public:
    int par[2005];
    int findRoot(int x){
        while(x != par[x]){
            x = par[x];
        }
        return x;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
        int numOfComps = n;
        for(auto edge: edges){
            int l = findRoot(edge[0]), r = findRoot(edge[1]);
            if(l != r){
                par[r] = l;
                numOfComps--;
            }
        }
        return numOfComps;
    }
};
