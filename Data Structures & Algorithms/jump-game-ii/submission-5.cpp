class Solution {
public:
    int jump(vector<int>& nums) {
        queue<pair<int, int>> pq;
        pq.push({0, 0});
        bool vis[1005] = {0};
        vis[0] = 1;
        while(!pq.empty()){
            pair<int, int> p = pq.front();
            int ind = p.second, jump = p.first;
            pq.pop();
            if(ind == nums.size() - 1){
                return jump;
            }
            for(int i = ind + 1; i <= min(ind + nums[ind], (int)nums.size()-1); i++){
                if(!vis[i]){
                    pq.push({jump + 1, i});
                    vis[i] = 1;
                }
            }
        }
        return 0;
    }
};
