class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int acc = 1, ans = 0, prevMul = 0, lastZero = -1;
        bool pos = false;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0 && !prevMul){
                prevMul = acc * nums[i];
            }
            else if(nums[i] == 0){
                if(prevMul){
                    ans = max(ans, acc / prevMul);
                }
                acc = 1, prevMul = 0;
                continue;
            }
            acc *= nums[i];
            ans = max(ans, acc);
            pos |= nums[i] > 0;
        }
        if(prevMul){
            ans = max(ans, acc / prevMul);
        }
        if(!pos && ans == 1){
            for(int i = 1; i < nums.size(); i++){
                pos = nums[i] != 0 && nums[i - 1] != 0;
            }
            if(!pos){
                return 0;
            }
        }
        return ans;
    }
};
