class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans = {""};
        if(digits.empty()){
            return {};
        }
        vector<string> mp = {"abc", "def", "ghi", "jkl", "mno", "pqrs",
        "tuv", "wxyz"};
        for(int i = 0; i < digits.size(); i++){
            vector<string> building;
            for(auto& cur: ans){
                for(int j = 0; j < mp[digits[i] - '2'].size(); j++){
                    building.push_back(cur + mp[digits[i] - '2'][j]);
                }
            }
            ans = building;
        }
        return ans;
    }
};
