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
        bool dp[101][5001] = {};
        for(int i = 0; i < nums.size() - 1; i++){
            dp[i][0] = true;
        }
        for(int i = 1; i <= nums.size(); i++){
            for(int j = 0; j <= targ; j++){
                if(dp[i - 1][j]){
                    dp[i][j + nums[i - 1]] = true;
                    dp[i][j] = true;
                }
            }
        }
        for(int i = 1; i <= nums.size(); i++){
            if(dp[i][targ]){
                return true;
            }
        }
        return false;
    }
};
