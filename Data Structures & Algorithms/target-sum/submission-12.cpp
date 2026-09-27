#include <cstring>
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum[20];
        sum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sum[i] = sum[i - 1] + nums[i];
        }
        unordered_map<int, int> dp[20];
        dp[0][nums[0]]++;
        dp[0][nums[0] * -1]++;
        for(int i = 1; i < nums.size(); i++){
            for(auto& p: dp[i - 1]){
                dp[i][p.first + nums[i]] += p.second;
                dp[i][p.first - nums[i]] += p.second;
            }
        }
        return dp[nums.size() - 1][target];
    }
};
