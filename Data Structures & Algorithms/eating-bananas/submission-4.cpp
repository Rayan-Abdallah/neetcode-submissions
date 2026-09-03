class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9;
        int ans = 1e9;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            long long cnt = 0;
            for(auto& p:piles){
                cnt += (p + mid - 1) / mid;
            }
            if(cnt <= h){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};
