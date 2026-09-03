class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int> > wait;
        vector<int> res(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            while(!wait.empty()){
                if(temperatures[i] <= wait.top().first){
                    break;
                }
                pair<int, int> p = wait.top();
                wait.pop();
                res[p.second] = (i - p.second);
            }
            wait.push({temperatures[i], i});
        }
        return res;
    }
};
