class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int> > acc[31];
        sort(nums.begin(), nums.end());
        for(int i = 2; i <= target; i++){
            vector<vector<int> > possible;
            for(auto num: nums){
                if(i - num == 0){
                    vector<int> cur;
                    cur.push_back(num);
                    possible.push_back(cur);
                }
                else if(i - num > 0){
                    if(acc[i - num].size() > 0){
                        vector<int> cur;
                        for(int j = 0; j < acc[i - num].size(); j++){
                            cur = acc[i-num][j];
                            cur.push_back(num);
                            possible.push_back(cur);
                        }
                    }
                }
            }
            for(auto& v: possible){
                sort(v.begin(), v.end());
            }
            sort(possible.begin(), possible.end());
            if(!possible.empty()){
                acc[i].push_back(possible[0]);
            }
            for(int j = 1; j < possible.size();j++){
                if(possible[j].size() != possible[j - 1].size()){
                    acc[i].push_back(possible[j]);
                    continue;
                }
                for(int k = 0; k < possible[j].size(); k++){
                    if(possible[j][k] != possible[j-1][k]){
                        acc[i].push_back(possible[j]);
                        k = possible[j].size();
                        continue;
                    }
                }
            }
        }
        vector<vector<int> > ans = acc[target];
        return ans;
    }
};
