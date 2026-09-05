class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[nums.size() - 1] = 0;
        for(int i = nums.size() - 2; i >= 0; i--){
            dp[i] = 1005;
            for(int j = i + 1; j <= min((int)nums.size() - 1, nums[i] + i); j++){
                dp[i] = min(dp[i], 1 + dp[j]);
            }
        }
        return dp[0];
    }
};
