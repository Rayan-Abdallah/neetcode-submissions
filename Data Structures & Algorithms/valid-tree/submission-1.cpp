class Solution {
public:
    vector<int> adj[2005];
    bool acyclic = true;
    bool vis[2005] = {0};
    void checkCycle(int curNode, int par){
        if(vis[curNode]){
            return;
        }
        vis[curNode] = true;
        for(int i = 0; i < adj[curNode].size(); i++){
            if(vis[adj[curNode][i]]){
                if(adj[curNode][i] != par){
                    acyclic = false;
                    return;
                }
            }
            checkCycle(adj[curNode][i], curNode);
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        checkCycle(0, -1);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                return false;
            }
        }
        return acyclic;
    }
};
