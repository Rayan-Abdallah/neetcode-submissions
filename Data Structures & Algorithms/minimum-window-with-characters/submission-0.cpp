
#include <unordered_map>
#include <set>
class Solution {
public:
    string minWindow(string s, string t) {
        int quotaSize = t.length();
        int quotaCnt[128] = {0};
        for(auto c: t){
            quotaCnt[c - 'A']++;
        }
        queue<int> locs[128];
        set<int> allLocs;
        int l = 2000, r = 4000;
        int startL = 0, startR = 0;
        int cnt[128] = {0};
        int curCnt = 0;
        for(int i = 0; i < s.size(); i++){
            int ind = s[i] - 'A';
            if(cnt[ind] < quotaCnt[ind]){
                cnt[ind]++;
                locs[ind].push(i);
                allLocs.insert(i);
                curCnt++;
            }
            else if(quotaCnt[ind] && cnt[ind] == quotaCnt[ind]){
                allLocs.erase(locs[ind].front());
                locs[ind].pop();
                locs[ind].push(i);
                allLocs.insert(i);
            }
            if(curCnt == quotaSize){
                auto it = allLocs.begin();
                startL = *it;
                it = allLocs.end();
                it--;
                startR = *it;
                if(startR - startL < r - l){
                    r = startR;
                    l = startL;
                }
            }
        }
        string ans = "";
        if(l == 2000){
            return ans;
        }
        for(int i = l; i <= r; i++){
            ans += s[i];
        }
        return ans;
    }
};
