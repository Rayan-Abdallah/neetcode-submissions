#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> visited;
        vector<int> ans;
        pair<int, int> p = {0, 0};
        for(int i = nums.size() - 1; i >= 0; i--){
            visited[nums[i]] = i + 1;
        }
        for(int i = 0; i < nums.size(); i++){
            int rem = target - nums[i];
            if(visited[rem]){
                p = {i, visited[rem] - 1};
                break;
            }
        }
        if(p.first == p.second){
            int val = nums[p.first];
            for(int i = p.first + 1; i < nums.size(); i++){
                int rem = target - nums[i];
                if(visited[rem]){
                    p = {i, visited[rem] - 1};
                    break;
                }
            }
            if(p.first > p.second){
                ans.push_back(p.second);
                ans.push_back(p.first);
                return ans;
            }
        }
        ans.push_back(p.first);
        ans.push_back(p.second);
        return ans;
    }
};
