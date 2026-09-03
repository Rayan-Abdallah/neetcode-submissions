class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int tempInd[101];
        for(int i = 1; i <= 100; i++){
            tempInd[i] = 200001;
        }
        vector<int> res(temperatures.size(), 200001);
        for(int i = temperatures.size() - 1; i >= 0; i--){
            int mn = -1;
            for(int j = temperatures[i] + 1; j <= 100; j++){
                if(tempInd[j] != 200001){
                    res[i] = min(res[i], (tempInd[j] - i));
                }
            }
            tempInd[temperatures[i]] = i;
        }
        for(auto& v: res){
            if(v > 100000){
                v = 0;
            }
        }
        return res;
    }
};
