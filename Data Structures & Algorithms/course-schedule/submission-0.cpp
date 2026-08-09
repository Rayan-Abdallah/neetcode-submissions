class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[1005];
        int inDeg[1005] = {0};
        for(int i = 0; i < prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDeg[prerequisites[i][0]]++;
        }
        queue<int> cur;
        int finished = 0;
        for(int i = 0; i < numCourses; i++){
            if(!inDeg[i]){
                cur.push(i);
                finished++;
            }
        }
        while(!cur.empty()){
            int course = cur.front();
            cur.pop();
            for(auto node: adj[course]){
                if(inDeg[node] > 0){
                    inDeg[node]--;
                    if(!inDeg[node]){
                        finished++;
                        cur.push(node);
                    }
                }
            }
        }
        return finished == numCourses;
    }
};
