class Solution {
public:
    vector<int> seps;
    string encode(vector<string>& strs) {
        string ans = "";
        for(auto& s: strs){
            ans += s;
            seps.push_back(ans.size());
            ans+=' ';
        }
        return ans;
    }

    vector<string> decode(string s) {
        string temp = "";
        int ind = 0;
        vector<string> ans;
        for(int i = 0; i < s.size(); i++){
            if(i == seps[ind]){
                ans.push_back(temp);
                temp = "";
                ind++;
                continue;
            }
            temp += s[i];
        }
        return ans;
    }
};
