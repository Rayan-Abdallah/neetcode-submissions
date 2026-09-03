#include <string>

class Solution {
public:
    int stoi(string& s){
        bool neg = false;
        int i = 0;
        if(s[0] == '-'){
            neg = true;
            i++;
        }
        int res = 0;
        for(i; i < s.size(); i++){
            res *= 10;
            res += (s[i] - '0');
        }
        if(neg){
            res *= -1;
        }
        return res;
    }

    int evalRPN(vector<string>& tokens) {
        bool startOp = true, start = true;
        deque<int> dq;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "-"){
                int r = dq.back();
                dq.pop_back();
                int l = dq.back();
                dq.pop_back();
                if(tokens[i] == "+"){
                    l += r;
                }
                else if(tokens[i] == "*"){
                    l *= r;
                }
                else if(tokens[i] == "/"){
                    l /= r;
                }
                else{
                    l -= r;
                }
                dq.push_back(l);
            }
            else{
                dq.push_back(stoi(tokens[i]));
            }
        }
        return dq.front();
    }
};
