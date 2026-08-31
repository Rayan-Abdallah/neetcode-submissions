class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> leftMax(n), rightMax(n), ans;
        for(int i = 0; i < n; i++){
            if(i % k == 0){
                leftMax[i] = nums[i];
            }
            else{
                leftMax[i] = max(leftMax[i - 1],nums[i]);
            }
        }
        rightMax[n-1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--){
            if(i % k == 0){
                rightMax[i] = nums[i];
            }
            else{
                rightMax[i] = max(rightMax[i + 1], nums[i]);
            }
        }
        for(int i = 0; i < n - k + 1; i++){
            ans.push_back(max(leftMax[i + k - 1], rightMax[i]));
        }
        return ans;
    }
};
