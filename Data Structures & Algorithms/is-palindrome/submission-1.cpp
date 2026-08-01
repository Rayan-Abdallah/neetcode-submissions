class Solution {
public:
    bool isPalindrome(string s) {
        string acc = "";
        for(auto c: s){
            if( c >= 'A' && c <= 'Z'){
                acc += (char)(c - 'A' + 'a');
            }
            else if(( c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
                acc += c;
            }
        }
        bool ans = true;
        for(int i = 0; i < acc.size()>>1;i++){
            if(acc[i] != acc[acc.size() - i - 1]){
                ans = false;
                break;
            }
        }
        return ans;
    }
};
