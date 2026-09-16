class Solution {
public:
    bool isValid(string s) {
        stack<char> op;
        for(int i = 0; i < s.size(); i++){
            if(op.size() == 0){
                if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                    return false;
                }
                op.push(s[i]);
            }
            else{
                if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                    op.push(s[i]);
                }
                else{
                    char cur = op.top();
                    op.pop();
                    if((cur == '(' && s[i] == ')') || 
                    (cur == '{' && s[i] == '}') || 
                    (cur == '[' && s[i] == ']')){
                        continue;
                    }
                    return false;
                }
            }
        }
        return op.empty();
    }
};
