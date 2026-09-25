class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool fst = false, scnd = false, thrd = false;
        for(auto& v: triplets){
            if(v[0] == target[0] && v[1] <= target[1] && v[2] <= target[2]){
                fst = true;
                break;
            }
        }
        if(!fst){
            return false;
        }
        for(auto& v: triplets){
            if(v[1] == target[1] && v[0] <= target[0] && v[2] <= target[2]){
                scnd = true;
                break;
            }
        }
        if(!scnd){
            return false;
        }
        for(auto& v: triplets){
            if(v[2] == target[2] && v[0] <= target[0] && v[1] <= target[1]){
                thrd = true;
                break;
            }
        }
        return fst && scnd && thrd;
    }
};
