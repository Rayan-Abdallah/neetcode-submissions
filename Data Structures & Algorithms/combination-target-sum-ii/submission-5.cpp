class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<vector<int> > > dp(31), newDp(31);
        dp[target] = {{}};
        sort(candidates.begin(), candidates.end());
        int cntOfRepeats = 0;
        int startingInd = candidates.size() - 1;
        for(int i = startingInd; i >= 0; i--){
            if(i < startingInd && candidates[i] == candidates[i + 1]){
                cntOfRepeats++;
            } else{
                cntOfRepeats = 0;
            }
            for(int j = target; j >= 0; j--){
                newDp[j] = dp[j];
                if(candidates[i] + j > target){
                    continue;
                }
                vector<vector<int> > *atPos = &dp[candidates[i] + j];
                vector<int> newPos = {};
                int compOnRepeats = 0;
                for(auto& v: *atPos){
                    for(auto& elem: v){
                        if(elem == candidates[i]){
                            compOnRepeats++;
                        } else {
                            break;
                        }
                    }
                    if(compOnRepeats != cntOfRepeats){
                        compOnRepeats = 0;
                        continue;
                    }
                    newPos = {candidates[i]};
                    newPos.insert(newPos.end(), v.begin(), v.end());
                    newDp[j].push_back(newPos);
                    compOnRepeats = 0;
                    newPos = {};
                }
            }
            dp = newDp;
        }
        return dp[0];
    }
};
