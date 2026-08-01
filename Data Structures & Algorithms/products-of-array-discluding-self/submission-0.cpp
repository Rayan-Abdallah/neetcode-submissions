class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long prod = 1;
        int zeroCnt = 0, zeroInd = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                zeroCnt++;
                zeroInd = i;
                continue;
            }
            prod *= nums[i];
        }
        vector<int> ans;
        if(zeroCnt > 1){
            for(int i = 0; i < nums.size(); i++){
                ans.push_back(0);
            }
        }
        else if(zeroCnt == 1){
            for(int i = 0; i < zeroInd; i++){
                ans.push_back(0);
            }
            ans.push_back(prod);
            for(int i = zeroInd + 1; i < nums.size(); i++){
                ans.push_back(0);
            }
        }
        else{
            for(int i = 0; i < nums.size(); i++){
                prod /= nums[i];
                ans.push_back(prod);
                prod *= nums[i];
            }
        }
        return ans;
    }
};
