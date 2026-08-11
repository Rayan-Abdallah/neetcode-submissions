class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int finL = 0, finR = 0, finLen = 1;
        for(int i = 0; i < s.size(); i++){
            int l = i, r = i + 1, len = 0;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                l--;
                r++;
                len+=2;
            }
            if(len > finLen){
                finLen = len;
                finL = i + 1 - len/2;
                finR = i + len/2;
            }
            l = i - 1, r = i + 1, len = 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                l--;
                r++;
                len+=2;
            }
            if(len > finLen){
                finLen = len;
                finL = i - len/2;
                finR = i + len/2;
            }
        }
        for(int i = finL; i<=finR; i++){
            ans += s[i];
        }
        return ans;
    }
};
