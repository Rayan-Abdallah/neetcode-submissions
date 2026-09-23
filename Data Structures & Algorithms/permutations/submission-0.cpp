class Solution {
private:
    vector<vector<int> > ans;
public:
    void rec(vector<int>& l, vector<int> r){
        if(r.empty()){
            ans.push_back(l);
        }
        for(int i = 0; i < r.size(); i++){
            l.push_back(r[i]);
            vector<int> copy;
            for(int j = 0; j < r.size(); j++){
                if(i != j){
                    copy.push_back(r[j]);
                }
            }
            rec(l, copy);
            l.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> l;
        rec(l, nums);
        return ans;
    }
};
