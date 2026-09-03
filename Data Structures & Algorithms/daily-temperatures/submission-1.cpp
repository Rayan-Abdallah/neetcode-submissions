class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int tempInd[101] = {0};
        vector<int> res(temperatures.size(), 100001);
        for(int i = temperatures.size() - 1; i >= 0; i--){
            for(int j = temperatures[i] + 1; j <= 100; j++){
                res[i] = tempInd[j] != 0 ? min(res[i], (tempInd[j] - i)) : res[i];
            }
            res[i] = res[i] == 100001 ? 0 : res[i];
            tempInd[temperatures[i]] = i;
        }
        return res;
    }
};
