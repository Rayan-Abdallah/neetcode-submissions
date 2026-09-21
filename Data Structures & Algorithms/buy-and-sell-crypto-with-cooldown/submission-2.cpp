class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dpSell[5001][1001] = {0};
        int dpNoBuy[5001] = {0};
        for(int i = 0; i <= 1000; i++){
            dpSell[prices.size() - 1][i] = prices[prices.size() - 1] - i;
        }
        for(int i = prices.size() - 2; i >= 0; i--){
            for(int j = 0; j <= 1000; j++){
                dpSell[i][j] = max(dpSell[i + 1][j], dpNoBuy[i + 1] + prices[i] - j);
            }
            dpNoBuy[i] = max(dpNoBuy[i + 1], dpSell[i + 2][prices[i + 1]]);
        }
        return max(dpNoBuy[0], dpSell[1][prices[0]]);
    }
};
