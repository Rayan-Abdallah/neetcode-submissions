class Solution {
public:
    int numDistinct(string s, string t) {
        unordered_map<char, vector<int> > possiblePositions;
        unordered_map<char, int> curCnt;
        unordered_map<int, int> curSumPosToPath;
        for(int i = 0; i < t.size(); i++){
            possiblePositions[t[i]].push_back(i);
        }
        curSumPosToPath[t.size()] = 1;
        for(int i = s.size() - 1; i >= 0; i--){
            curCnt[s[i]]++;
            for(auto ind: possiblePositions[s[i]]){
                curSumPosToPath[ind] += curSumPosToPath[ind + 1];
            }
        }
        return curSumPosToPath[0];
    }
};
