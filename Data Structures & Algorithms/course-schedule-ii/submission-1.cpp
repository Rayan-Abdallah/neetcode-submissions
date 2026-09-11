class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDeg(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto p: prerequisites){
            inDeg[p[0]]++;
            adj[p[1]].push_back(p[0]);
        }
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i < numCourses; i++){
            if(!inDeg[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int ind = q.front();
            q.pop();
            ans.push_back(ind);
            for(auto v: adj[ind]){
                inDeg[v]--;
                if(!inDeg[v]){
                    q.push(v);
                }
            }
        }
        if(ans.size() != numCourses){
            return {};
        }
        return ans;
    }
};
