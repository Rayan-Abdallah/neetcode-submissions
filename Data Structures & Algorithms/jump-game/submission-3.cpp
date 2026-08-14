class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[nums.size() - 1] = true;
        int closestTrue = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; i--){
            if(nums[i] + i >= closestTrue){
            dp[i] = true;
            closestTrue = i;
            }
        }
        return dp[0];
    }
};
