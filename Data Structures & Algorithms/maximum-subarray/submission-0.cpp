class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1), suffix(n + 1);
        int sum = 0, ans = nums[0];
        for(int i = 0; i < n; i++){
            sum += nums[i];
            prefix[i] = sum;
            ans = max(ans, prefix[i]);
            if(prefix[i] < 0){
                sum = 0;
            }
        }
        sum = 0;
        for(int i = n - 1; i >= 0; i--){
            sum += nums[i];
            suffix[i] = sum;
            ans = max(ans, suffix[i]);
            if(suffix[i] < 0){
                sum = 0;
            }
        }
        return ans;
    }
};
