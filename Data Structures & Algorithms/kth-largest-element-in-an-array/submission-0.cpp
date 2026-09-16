class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int st = 1000, en = -1000;
        for(auto v: nums){
            mp[v]++;
            st = min(v, st);
            en = max(v, en);
        }
        int tally = 0;
        for(int i = en; i >= st; i--){
            if(mp.contains(i)){
                tally += mp[i];
                if(tally >= k){
                    return i;
                }
            }
        }
        return 0;
    }
};
