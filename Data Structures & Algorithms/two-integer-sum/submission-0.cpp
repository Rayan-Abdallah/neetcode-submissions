#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> visited;
        unordered_map<int, bool> dup;
        for(int i = 0; i < nums.size(); i++){
            if(!visited[nums[i]]){
                visited[nums[i]] = i + 1;
            }
            else if(visited[nums[i]]!=0 && !dup[nums[i]]){
                dup[nums[i]] = 1;
                visited[nums[i]] = i + 1;
            }
        }
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int rem = target - nums[i];
            if(rem != nums[i] && visited[rem] != 0){
                ans.push_back(i);
                ans.push_back(visited[rem] - 1);
                break;
            }
            else if(rem == nums[i] && dup[nums[i]]){
                ans.push_back(i);
                ans.push_back(visited[rem] - 1);
                break;
            }
        }
        return ans;
    }
};
