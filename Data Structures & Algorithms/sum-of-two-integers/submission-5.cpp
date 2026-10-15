class Solution {
public:
    int getSum(int a, int b) {
        vector<int> digits;
        int carry = 0;
        int cnt = 0;
        unsigned int realA, realB;
        realA = a;
        realB = b;
        while(realA != 0 || realB != 0 || carry > 0){
            bool l = (realA & 1), r = (realB & 1);
            realA >>= 1;
            realB >>= 1;
            if(l & r & carry){
                digits.push_back(1);
            }
            else if((l & carry) || (l & r) || (r & carry)){
                digits.push_back(0);
                carry = 1;
            } else if(l | r | carry){
                digits.push_back(1);
                carry = 0;
            } else{
                digits.push_back(0);
            }
        }
        int res = 0;
        for(int i = digits.size() - 1; i >= 0; i--){
            res |= digits[i];
            if(i != 0){
                res <<= 1;
            }
        }
        return res;
    }
};
