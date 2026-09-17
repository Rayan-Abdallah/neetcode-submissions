class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> s;
        queue<pair<int, int> > cool;
        int initCnt[26] = {0};
        for(auto c: tasks){
            initCnt[c - 'A']++;
        }
        for(int i = 0; i < 26; i++){
            if(initCnt[i] > 0){
                s.push(initCnt[i]);
            }
        }
        int ans = 0;
        while(!s.empty() || !cool.empty()){
            while(!cool.empty() && cool.front().second <= ans){
                s.push(cool.front().first);
                cool.pop();
            }
            if(!s.empty()){
                ans++;
                int freq = s.top();
                s.pop();
                freq--;
                if(freq > 0){
                    cool.push({freq, ans + n});
                }
            }
            else{
                ans = cool.front().second;
            }
        }
        return ans;
    }
};
