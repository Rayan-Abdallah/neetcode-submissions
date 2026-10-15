#include <climits>
class Solution {
public:
    int reverse(int x) {
        if(x == 0){
            return 0;
        }
        vector<int> digits;
        long long low = INT_MIN, high = INT_MAX;
        long long startingVal = x;
        if(x < 0){
            x *= -1;
        }
        while(x > 0){
            digits.push_back(x % 10);
            x /= 10;
        }
        long long res = 0;
        int startingInd = 0;
        while(startingInd < digits.size() && digits[startingInd] == 0){
            startingInd++;
        }
        for(int i = startingInd; i < digits.size(); i++){
            res += digits[i];
            res *= 10;
        }
        res /= 10;
        if(startingVal < 0){
            res *= -1;
        }
        if(res < low || res > high){
            return 0;
        }
        int ans = res;
        return ans;
    }
};
