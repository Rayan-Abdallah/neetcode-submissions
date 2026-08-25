class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, ans = nums[0];
        for(int i = 0; i < n; i++){
            sum += nums[i];
            ans = max(ans, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        sum = 0;
        for(int i = n - 1; i >= 0; i--){
            sum += nums[i];
            ans = max(ans, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return ans;
    }
};
