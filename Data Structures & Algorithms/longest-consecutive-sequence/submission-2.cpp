#include <unordered_map>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int ans = 1;
        sort(nums.begin(), nums.end());
        int len = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1] + 1){
                len++;
            }
            else if(nums[i] != nums[i -1]){
                ans = max(len, ans);
                len = 1;            
            }
        }
        ans = max(ans, len);
        return ans;
    }
};
