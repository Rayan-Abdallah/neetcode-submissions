class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        for(int i = 0; i < k; i++){
            s.insert(nums[i]);
        }
        vector<int> ans;
        auto it = s.end();
        it--;
        ans.push_back(*it);
        for(int i = 1; i < nums.size() - k + 1; i++){
            s.erase(s.find(nums[i-1]));
            s.insert(nums[i + k - 1]);
            it = s.end();
            it--;
            ans.push_back(*it);
        }
        return ans;
    }
};
