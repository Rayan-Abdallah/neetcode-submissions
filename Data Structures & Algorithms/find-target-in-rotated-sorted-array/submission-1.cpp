class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivotInd = 0;
        if(nums[0] > nums[nums.size() - 1]){
            int l = 0, r = nums.size() - 1;
            int minVal = 1001;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(nums[mid] >= nums[0]){
                    l = mid + 1;
                }
                else{
                    if(nums[mid] < minVal){
                        pivotInd = mid;
                        minVal = nums[mid];
                    }
                    r = mid - 1;
                }
            }
        }
        auto binSearch = [&nums, target](int l, int r){
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(nums[mid] == target){
                    return mid;
                }
                else if(nums[mid] > target){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            return -1;
        };
        
        return max(binSearch(0, pivotInd), 
        binSearch(pivotInd, nums.size() - 1));
    }
};
