class Solution {
    vector<vector<int> > res;
    void backTrack(vector<int>& nums, vector<int>& cnt, int i, int sum){
        if(sum == 0){
            res.push_back(nums);
            return;
        }
        if(sum < 0 || i == cnt.size()){
            return;
        }
        if(cnt[i] > 0){
            cnt[i]--;
            nums.push_back(i);
            backTrack(nums, cnt, i, sum - i);
            nums.pop_back();
            cnt[i]++;
        }
        backTrack(nums, cnt, i + 1, sum);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ans, cnt(target + 1, 0);
        sort(candidates.begin(), candidates.end());
        for(auto val: candidates){
            if(val <= target){
                cnt[val]++;
            }
        }
        backTrack(ans, cnt, 1, target);
        return res;
    }
};
