class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        if(nums[l] <= nums[r]){
            return nums[l];
        }
        int minVal = 1001;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] >= nums[0]){
                l = mid + 1;
            }
            else{
                minVal = min(minVal, nums[mid]);
                r = mid - 1;
            }
        }
        return minVal;
    }
};
