class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0'){
            return 0;
        }
        if(s.size() == 1){
            return 1;
        }
        int arr[101];
        for(int i = 0; i < s.size(); i++){
            arr[i] = s[i] - '0';
        }
        int dp[101] = {0};
        dp[0] = 1;
        dp[1] = 1;
        if(arr[1] != 0 && (arr[0] == 1 || (arr[0] == 2 && arr[1] <= 6))){
            dp[1] = 2;
        }
        if(arr[1] == 0 && arr[0] > 2){
            return 0;
        }
        for(int i = 2; i < s.size(); i++){
            if(arr[i] == 0){
                if(arr[i - 1] == 0 || arr[i - 1] > 2){
                    return 0;
                }
                dp[i] = dp[i - 2];
                continue;
            }
            if((arr[i-1] == 1) || (arr[i-1] == 2 && arr[i] <= 6)){
                dp[i] += dp[i - 2];
            }
            dp[i] += dp[i - 1];
        }
        return dp[s.size()-1];
    }
};
