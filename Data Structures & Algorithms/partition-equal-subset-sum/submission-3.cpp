class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto v: nums){
            sum += v;
        }
        if(sum % 2 != 0){
            return false;
        }
        int targ = sum / 2;
        vector<bool> dp(5001, 0);
        dp[0] = true;
        for(int i = 1; i <= nums.size(); i++){
            vector<bool> newDp(5001, 0);
            for(int j = 0; j <= targ; j++){
                if(dp[j]){
                    newDp[j + nums[i - 1]] = true;
                    newDp[j] = true;
                }
            }
            dp = newDp;
        }
        return dp[targ];
    }
};
