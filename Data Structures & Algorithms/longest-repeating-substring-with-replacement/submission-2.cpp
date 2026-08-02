#include <set>
#include <cstring>
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 1, r = s.size();
        int ans = 1;
        while (l <= r){
            int mid = l + (r - l)/2;
            int dups[26];
            set<pair<int, int> > cnt;
            for(int i = 0; i < 26; i++){
                dups[i] = 0;
            }
            for(int i = 0; i < mid - 1; i++){
                dups[s[i] - 'A']++;
            }
            for(int i = 0; i < 26; i++){
                cnt.insert({dups[i], i});
            }
            bool possible = false;
            for(int i = mid - 1; i < s.size(); i++){
                int ind = s[i] - 'A';
                cnt.erase({dups[ind], ind});
                dups[ind]++;
                cnt.insert({dups[ind], ind});
                auto it = cnt.end();
                it--;
                pair<int, int> p = *it;
                if(p.first + k >= mid){
                    possible = true;
                    break;
                }
                ind = s[i - mid + 1] - 'A';
                cnt.erase({dups[ind], ind});
                dups[ind]--;
                cnt.insert({dups[ind], ind});
            }
            if(possible){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return ans;
    }
};
