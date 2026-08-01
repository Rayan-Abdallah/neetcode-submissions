#include <map>
#include <unordered_map>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp;
        bool ans = false;
        for(auto i: nums){
            if(mp[i]){
                ans = true;
                break;
            }
            mp[i] = true;
        }
        return ans;
    }
};