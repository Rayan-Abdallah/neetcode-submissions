class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans = {""};
        if(digits.empty()){
            return {};
        }
        unordered_map<int, string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        for(int i = 0; i < digits.size(); i++){
            vector<string> building;
            for(auto& cur: ans){
                for(int j = 0; j < mp[digits[i] - '0'].size(); j++){
                    building.push_back(cur + mp[digits[i] - '0'][j]);
                }
            }
            ans = building;
        }
        return ans;
    }
};
