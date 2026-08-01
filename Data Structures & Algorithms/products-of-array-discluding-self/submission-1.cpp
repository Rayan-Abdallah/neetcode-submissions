class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long prod = 1;
        int zeroCnt = 0, zeroInd = -1;
        vector<int> pref;
        vector<int> suff;
        pref.push_back(1);
        for(int i = 0; i < nums.size(); i++){
            prod *= nums[i];
            pref.push_back(prod);
        }
        prod = 1;
        suff.push_back(1);
        for(int i = nums.size() - 1; i >= 0; i--){
            prod*=nums[i];
            suff.push_back(prod);
        }
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            ans.push_back(pref[i] * suff[nums.size() - i - 1]);
        }
        return ans;
    }
};
