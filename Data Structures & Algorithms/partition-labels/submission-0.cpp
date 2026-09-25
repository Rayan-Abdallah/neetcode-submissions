class Solution {
public:
    vector<int> partitionLabels(string s) {
        int en[26] = {-1};
        for(int i = 0; i < s.size(); i++){
            en[s[i] - 'a'] = i;
        }
        vector<int> res;
        int r = en[s[0] - 'a'];
        int sz = 0;
        for(int i = 0; i < s.size(); i++){
            sz++;
            if(i == r){
                res.push_back(sz);
                sz = 0;
                if(i + 1 != s.size()){
                    r = en[s[i + 1] - 'a'];
                }
            }
            else{
                r = max(r, en[s[i] - 'a']);
            }
        }
        if(sz != 0){
            res.push_back(sz);
        }
        return res;
    }
};
