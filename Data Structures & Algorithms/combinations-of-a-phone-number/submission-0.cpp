class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()){
            return ans;
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
        std::function<void(vector<int>&, int)> rec;
        rec = [&](vector<int>& path, int pos){
            if(pos == digits.size()){
                string res;
                for(int i = 0; i < pos; i++){
                    res += mp[digits[i] - '0'][path[i]];
                }
                ans.push_back(res);
                return;
            }
            for(int i = 0; i < mp[digits[pos] - '0'].size(); i++){
                path.push_back(i);
                rec(path, pos + 1);
                path.pop_back();
            }
        };
        vector<int> p;
        rec(p, 0);
        return ans;
    }
};
