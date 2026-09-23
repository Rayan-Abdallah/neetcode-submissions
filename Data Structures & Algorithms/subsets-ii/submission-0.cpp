class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        for(int i = 0; i < 1 << nums.size(); i++){
            int x = i;
            vector<int> cur;
            for(int j = 0; j < nums.size(); j++){
                if((1 << j) & x){
                    cur.push_back(nums[j]);
                }
            }
            bool uniq = true;
            for(auto& v: ans){
                if(v.size() == cur.size()){
                    bool diff = false;
                    for(int j = 0; j < v.size(); j++){
                        if(v[j] != cur[j]){
                            diff = true;
                            break;
                        }
                    }
                    if(!diff){
                        uniq = false;
                        break;
                    }
                }
            }
            if(uniq){
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
