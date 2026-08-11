class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int acc = 1, ans = 0, prevMul = 0, ind = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0 && !prevMul){
                prevMul = acc * nums[i];
                ind = i;
            }
            else if(nums[i] == 0){
                if(prevMul && i > ind + 1){
                    ans = max(ans, acc / prevMul);
                }
                acc = 1, prevMul = 0;
                continue;
            }
            acc *= nums[i];
            ans = max(ans, acc);
        }
        if(prevMul && nums.size() > ind + 1){
            ans = max(ans, acc / prevMul);
        }
        return ans;
    }
};
