class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), curGas = 0;
        for(int i = 0; i < n; i++){
            curGas += (gas[i] - cost[i]);
        }
        if(curGas < 0){
            return -1;
        }
        int ans = -1, start = 0;
        curGas = 0;
        bool worked = false;
        while(!worked){
            worked = true;
            ans = start;
            for(int i = start; i < n + start; i++){
                int ind = i >= n ? i % n : i;
                curGas += (gas[ind] - cost[ind]);
                if(curGas < 0){
                    start = (i + 1) % n;
                    curGas = 0;
                    worked = false;
                    break;
                }
            }
        }
        return ans;
    }
};
