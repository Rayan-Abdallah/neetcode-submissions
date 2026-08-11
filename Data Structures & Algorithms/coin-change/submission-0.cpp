class Solution {
public:
    int INF = 1e9;
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        vector<int> dp;
        for(int i = 0; i <= amount; i++){
            dp.push_back(INF);
        }
        vector<int> usableCoins;
        for(auto c: coins){
            if(c <= amount){
                dp[c] = 1;
                usableCoins.push_back(c);
            }
        }
        for(int i = 1; i <= amount; i++){
            for(auto coin: usableCoins){
                if(i - coin >= 1){
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        if(dp[amount] == INF){
            return -1;
        }
        return dp[amount];
    }
};
