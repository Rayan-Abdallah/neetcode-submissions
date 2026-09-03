class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1, r = 1e9;
        long long ans = 1e9;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            long long cnt = 0;
            for(auto p:piles){
                cnt += p % mid != 0 ? (p / mid) + 1 : p / mid;
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
