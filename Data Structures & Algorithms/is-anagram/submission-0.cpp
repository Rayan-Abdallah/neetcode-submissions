class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0}, countt[26] = {0};
        for(auto c: s){
            count[c - 'a']++;
        }
        for(auto c: t){
            countt[c - 'a']++;
        }
        bool ans = true;
        for(int i=0;i<26;i++){
            ans &= (!(count[i] - countt[i]));
        }
        return ans;
    }
};
