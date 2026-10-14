class Solution {
private:
int ans[400];
int l[400], r[400];
int finale[200][400];
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        for(int i = 0; i < 400; i++){
            l[i] = 0, r[i] = 0, ans[i] = 0;
        }
        for(int i = 0; i < 200; i++){
            for(int j = 0; j < 400; j++){
                finale[i][j] = 0;
            }
        }
        int ind = num1.size() - 1;
        while(ind >= 0){
            l[399 - (num1.size() - ind - 1)] = num1[ind] - '0';
            ind--;
        }
        ind = num2.size() - 1;
        while(ind >= 0){
            r[399 - (num2.size() - ind - 1)] = num2[ind] - '0';
            ind--;
        }
        for(int i = 0; i < 200; i++){
            int carry = 0;
            for(int j = 399; j >= 0; j--){
                int res = l[399 - i] * r[j];
                res += carry;
                if(i == 0 && j == 399){
                    cout<< res << endl;
                }
                finale[i][399 - i - (399 - j)] += res % 10;
                carry = res / 10;
            }
        }
        int carry = 0;
        for(int i = 399; i >= 0; i--){
            int sumForRow = 0;
            for(int j = 0; j < 200; j++){
                sumForRow += finale[j][i];
            }
            ans[i] = ((sumForRow + carry) % 10);
            carry = (sumForRow + carry) / 10;
        }
        string res = "";
        int st = 0;
        while(ans[st] == 0){
            st++;
        }
        while(st < 400){
            res += (ans[st] + '0');
            st++;
        }
        if(res == ""){
            return ("0");
        }
        return res;
    }
};
