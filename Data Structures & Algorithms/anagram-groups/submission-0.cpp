#include <unordered_map>


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mp;
        for(auto& s: strs){
            string cpy = s;
            sort(cpy.begin(), cpy.end());
            mp[cpy].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto p: mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};
