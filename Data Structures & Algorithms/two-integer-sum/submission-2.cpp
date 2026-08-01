#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> visited;
        vector<int> ans;
        pair<int, int> p = {0, 0};
        for(int i = 0; i < nums.size(); i++){
            int rem = target - nums[i];
            if(visited[rem] && (!p.first || p.first > visited[rem])){
                p = {visited[rem], i + 1};
            }
            visited[nums[i]] = i + 1;
        }
        ans.push_back(p.first - 1);
        ans.push_back(p.second - 1);
        return ans;
    }
};
