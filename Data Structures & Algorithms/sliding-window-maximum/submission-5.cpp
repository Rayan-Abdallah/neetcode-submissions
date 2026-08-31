class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> indexes;
        for(int i = 0; i < k; i++){
            while(!indexes.empty() && nums[indexes.back()] <= nums[i]){
                indexes.pop_back();
            }
            indexes.push_back(i);
        }
        vector<int> ans;
        ans.push_back(nums[indexes.front()]);
        for(int i = 1; i < nums.size() - k + 1; i++){
            while(!indexes.empty() && indexes.front() < i){
                indexes.pop_front();
            }
            while(!indexes.empty() && (indexes.back() < i 
            || nums[indexes.back()] <= nums[i + k - 1])){
                indexes.pop_back();
            }
            indexes.push_back(i + k - 1);
            ans.push_back(nums[indexes.front()]);
        }
        return ans;
    }
};
