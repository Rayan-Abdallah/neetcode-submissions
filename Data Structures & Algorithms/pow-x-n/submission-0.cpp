class Solution {
public:
    double fastPow(double x, int n){
        if(n == 1){
            return x;
        }
        if(n == 0){
            return 1;
        }
        double ans = 1;
        if(n%2!=0){
            ans = x;
        }
        double res = fastPow(x, n/2);
        ans*=res;
        ans*=res;
        return ans;
    }
    double myPow(double x, int n) {
        if(n < 0){
            double ans = 1;
            ans /= fastPow(x, -1*n);
            return ans;
        }
        return fastPow(x, n);
    }
};
