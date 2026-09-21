class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dpSell[5001][1001] = {0};
        int dpNoBuy[5001] = {0}, dp[5001] = {0};
        for(int i = 0; i <= 1000; i++){
            dpSell[prices.size() - 1][i] = prices[prices.size() - 1] - i;
        }
        for(int i = prices.size() - 2; i >= 0; i--){
            for(int j = 0; j <= 1000; j++){
                dpSell[i][j] = dpNoBuy[i + 1] + prices[i] - j;
            }
            dpNoBuy[i] = dpNoBuy[i + 1];
            for(int j = i + 2; j < prices.size(); j++){
                dpNoBuy[i] = max(dpNoBuy[i], dpSell[j][prices[i + 1]]);
            }
        }
        int ans = dpNoBuy[0];
        for(int i = 1; i < prices.size(); i++){
            ans = max(ans, dpSell[i][prices[0]]);
        }
        return ans;
    }
};
