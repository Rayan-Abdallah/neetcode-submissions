#include <cstring>

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }
        int cnt[1005];
        memset(cnt, 0, sizeof(cnt));
        for(auto v: hand){
            cnt[v]++;
        }
        for(int i = 0; i <= 1000; i++){
            if(cnt[i] < 0){
                return false;
            }
            else if(cnt[i] != 0){
                if(i + groupSize - 1 > 1000){
                    return false;
                }
                for(int j = i + 1; j < i + groupSize; j++){
                    cnt[j] -= cnt[i];
                }
                cnt[i] = 0;
            }
        }
        return true;
    }
};
