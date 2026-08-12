class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int longest = 1;
        int dp[1005];
        dp[1] = nums[0];
        dp[0] = -1001;
        for(int i = 1; i < nums.size(); i++){
            int l = 1, r = longest;
            int ind = 0, val = nums[i];
            while(l <= r){
                int mid = l + (r - l)/2;
                if(dp[mid] > val){
                    r = mid - 1;
                }
                else if(dp[mid] == val){
                    l = r + 1;
                    ind = mid;
                }
                else{
                    ind = mid;
                    l = mid + 1;
                }
            }
            if(dp[ind] < val){
                dp[ind + 1] = val;
                longest = max(longest, ind + 1);
            }
        }
        return longest;
    }
};
