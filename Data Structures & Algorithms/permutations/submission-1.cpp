class Solution {
private:
    vector<vector<int> > ans;
public:
    void rec(vector<int>& l, unordered_set<int>& elems, vector<int>& nums){
        if(l.size() == nums.size()){
            ans.push_back(l);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!elems.contains(nums[i])){
                elems.insert(nums[i]);
                l.push_back(nums[i]);
                rec(l, elems, nums);
                l.pop_back();
                elems.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> elems;
        vector<int> l;
        rec(l, elems, nums);
        return ans;
    }
};
