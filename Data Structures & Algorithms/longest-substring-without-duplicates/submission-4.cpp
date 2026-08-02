#include <iostream>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return 0;
        }
        int maxSize = 1;
        int l = 0, r = 0;
        int lastLoc[128] = {-1};
        for(int i = 0; i < 128; i++){
            lastLoc[i] = -1;
        }
        for(int i = 0; i < s.size(); i++){
            int ind = s[i] - ' ';
            if(lastLoc[ind] < l){
                lastLoc[ind] = i;
            }
            else{
                maxSize = max(maxSize, r - l);
                l = lastLoc[ind] + 1;
                lastLoc[ind] = i;
            }
            r++;
        }
        maxSize = max(maxSize, r - l);
        return maxSize;
    }
};
