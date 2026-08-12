class Solution {
public:
    int uniquePaths(int m, int n) {
        int sum = m + n - 2;
        int mn = min(m, n) - 1;
        int muls[101] = {0};
        std::function<void(int, int*)> fac = [](int x, int* arr){
            int div = 2;
            while(x > 1){
                if(x % div == 0){
                    arr[div]++;
                    x /= div;
                    div = 2;
                }
                else{
                    div++;
                }
            }
        };
        for(int i = sum; i > sum - mn; i--){
            fac(i, muls);
        }
        int divs[101] = {0};
        for(int i = 2; i <= mn; i++){
            fac(i, divs);
        }
        int res = 1;
        for(int i = 2; i <= sum; i++){
            muls[i] -= divs[i];
            res *= pow(i, muls[i]);
        }
        return res;
    }
};
