class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> possiblePositions[200];
        vector<int> curCnt(200, 0);
        vector<int> curSumPosToPath(t.size() + 1, 0);
        for(int i = 0; i < t.size(); i++){
            possiblePositions[(int)t[i]].push_back(i);
        }
        curSumPosToPath[t.size()] = 1;
        for(int i = s.size() - 1; i >= 0; i--){
            curCnt[(int)s[i]]++;
            for(auto ind: possiblePositions[(int)s[i]]){
                curSumPosToPath[ind] += curSumPosToPath[ind + 1];
            }
        }
        return curSumPosToPath[0];
    }
};
