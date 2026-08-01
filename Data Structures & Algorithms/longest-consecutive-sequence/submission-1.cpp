#include <unordered_map>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> valToLen;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            valToLen[nums[i]] = valToLen[nums[i] - 1] + 1;
            ans = max(ans, valToLen[nums[i]]);
        }
        return ans;
    }
};
