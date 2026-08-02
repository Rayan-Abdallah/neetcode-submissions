class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sm = 100;
        int ans = 0;
        for(int i = 0; i < prices.size(); i++){
            sm = min(sm, prices[i]);
            ans = max(ans, prices[i] - sm);
        }
        return ans;
    }
};
