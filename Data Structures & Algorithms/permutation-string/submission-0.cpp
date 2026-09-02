class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        int cnt[26] = {0}, cur[26] = {0};
        for(int i = 0; i < s1.size(); i++){
            cnt[s1[i] - 'a']++;
            cur[s2[i] - 'a']++;
        }
        for(int i = s1.size(); i < s2.size(); i++){
            bool diff = false;
            for(int j = 0; j < 26; j++){
                if(cnt[j] != cur[j]){
                    diff = true;
                    break;
                }
            }
            if(!diff){
                return true;
            }
            cur[s2[i - s1.size()] - 'a']--;
            cur[s2[i] - 'a']++;
        }
        for(int j = 0; j < 26; j++){
            if(cnt[j] != cur[j]){
                return false;
            }
        }
        return true;
    }
};
