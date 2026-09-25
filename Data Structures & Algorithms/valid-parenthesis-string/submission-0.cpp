class Solution {
public:
    bool checkValidString(string s) {
        int op = 0, cl = 0;
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                op++;
            }
            else if(s[i] == ')'){
                cl++;
            }
            else{
                st.push(i);
            }
            if(cl > op){
                if(st.empty()){
                    return false;
                }
                int ind = st.top();
                st.pop();
                s[ind] = '(';
            }
        }
        if(op > cl){
            int dif = op - cl;
            if(dif <= st.size()){
                while(dif){
                    int ind = st.top();
                    st.pop();
                    s[ind] = ')';
                    dif--;
                }
                op = 0, cl = 0;
                for(int i = 0; i < s.size(); i++){
                    if(s[i] == '('){
                        op++;
                    }
                    else if(s[i] == ')'){
                        cl++;
                    }
                    if(cl > op){
                        return false;
                    }
                }
                if(op != cl){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};
