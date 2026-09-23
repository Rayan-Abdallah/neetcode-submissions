class Solution {
private:
    vector<string> ans;
    void rec(string& cur, int op, int n){
        if(op < 0){
            return;
        }
        if(cur.size() == n){
            if(op){
                return;
            }
            ans.push_back(cur);
            return;
        }
        cur += '(';
        rec(cur, op + 1, n);
        cur.pop_back();
        cur += ')';
        rec(cur, op - 1, n);
        cur.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        string cur = "";
        rec(cur, 0, n * 2);
        return ans;
    }
};
