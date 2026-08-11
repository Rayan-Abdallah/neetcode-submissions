class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0], nums[1]);
        }
        int dp[105][2] = {0};
        int revDp[105][2] = {0};
        int ans = 0;
        for(int i = 1; i < n - 1; i++){
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
            dp[i][1] = nums[i] + dp[i - 1][0];
            ans = max(max(dp[i][1], dp[i][0]), ans);
        }
        for(int i = n - 2; i > 0; i--){
            revDp[i][0] = max(revDp[i + 1][1], revDp[i + 1][0]);
            revDp[i][1] = nums[i] + revDp[i + 1][0];
            ans = max(max(revDp[i][1], revDp[i][0]), ans);
        }
        dp[n - 1][0] = max(dp[n - 2][1], dp[n - 2][0]);
        dp[n - 1][1] = nums[n-1] + dp[n - 2][0];
        revDp[0][0] = max(revDp[1][1], revDp[1][0]);
        revDp[0][1] = nums[0] + revDp[1][0];
        ans = max(max(dp[n - 1][0], dp[n - 1][1]), ans);
        ans = max(max(revDp[0][0], revDp[0][1]), ans);
        return ans;
    }
};
