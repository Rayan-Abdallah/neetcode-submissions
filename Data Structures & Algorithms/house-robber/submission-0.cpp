class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[105][2] = {0};
        for(int i = 0; i < n; i++){
            dp[i][1] += nums[i];
            if(i > 0){
                dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
                dp[i][1] += dp[i-1][0];
            }
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};
