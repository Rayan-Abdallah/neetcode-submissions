class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        set<pair<int, int>, greater<pair<int, int> > > s;
        int initCnt[26] = {0};
        int initPrev[26];
        for(auto c: tasks){
            initCnt[c - 'A']++;
        }
        for(int i = 0; i < 26; i++){
            if(initCnt[i] > 0){
                s.insert({initCnt[i], i});
            }
            initPrev[i] = -105;
        }
        int ans = 0;
        while(!s.empty()){
            auto it = s.begin();
            int prevAns = ans;
            int idl = 10000000;
            while(it != s.end()){
                pair<int, int> p = *it;
                int cnt = p.first, ind = p.second;
                if(ans - (initPrev[ind] + 1) < n){
                    it++;
                    idl = min(idl, initPrev[ind]);
                }
                else{
                    initPrev[ind] = ans;
                    ans++;
                    s.erase({cnt, ind});
                    cnt--;
                    if(cnt > 0){
                        s.insert({cnt, ind});
                    }
                    it = s.end();
                }
            }
            if(prevAns == ans){
                ans += (n - (ans - (idl + 1)));
            }
        }
        return ans;
    }
};
