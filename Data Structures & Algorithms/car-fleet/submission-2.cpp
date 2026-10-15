class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int ans = 0, n = position.size();
        vector<pair<int, int> > posToSpeed;
        for(int i = 0; i < n; i++){
            posToSpeed.push_back({position[i], speed[i]});
        }
        sort(posToSpeed.begin(), posToSpeed.end());
        double t = -1;
        for(int i = n - 1; i >= 0; i--){
            double arrivalTime =  target - posToSpeed[i].first;
            arrivalTime /= posToSpeed[i].second;
            if(arrivalTime > t){
                ans++;
                t = arrivalTime;
            }
        }
        return ans;
    }
};
