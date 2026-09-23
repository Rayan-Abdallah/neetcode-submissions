class Solution {
private:
    vector<vector<string> > ans;
    bool checkPalind(const string& cur){
        for(int i = 0; i < cur.size() / 2; i++){
            if(cur[i] != cur[cur.size() - i - 1]){
                return false;
            }
        }
        return true;
    }
    void rec(vector<string>& soFar, string& cur, int ind, string& s){
        if(ind == s.size()){
            if(!checkPalind(cur)){
                return;
            }
            if(cur != ""){
                soFar.push_back(cur);
            }
            ans.push_back(soFar);
            if(cur != ""){
                soFar.pop_back();
            }
            return;
        }
        cur += s[ind];
        rec(soFar, cur, ind + 1, s);
        cur.pop_back();
        if(cur != "" && checkPalind(cur)){
            soFar.push_back(cur);
            cur = "";
            cur += s[ind];
            rec(soFar, cur, ind + 1, s);
            cur = soFar[soFar.size() - 1];
            soFar.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> soFar;
        string cur = "";
        rec(soFar, cur, 0, s);
        return ans;
    }
};
