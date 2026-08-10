class Solution {
public:
    int par[2005], size[2005];
    int findRoot(int x){
        while(x != par[x]){
            x = par[x];
        }
        return x;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++){
            par[i] = i;
            size[i] = 1;
        }
        int numOfComps = n;
        for(auto edge: edges){
            int l = findRoot(edge[0]), r = findRoot(edge[1]);
            if(l != r){
                if(size[l] > size[r]){
                    size[l] += size[r];
                    par[r] = l;
                }
                else{
                    size[r] += size[l];
                    par[l] = r;
                }
                numOfComps--;
            }
        }
        return numOfComps;
    }
};
