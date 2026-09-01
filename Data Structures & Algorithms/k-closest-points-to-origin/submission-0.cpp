class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>> sortByDis;
        for(auto v: points){
            int dist = v[0]*v[0] + v[1]*v[1];
            sortByDis.push_back({dist, v});
        }
        sort(sortByDis.begin(), sortByDis.end());
        vector<vector<int>> res;
        for(int i = 0; i < k; i++){
            res.push_back(sortByDis[i].second);
        }
        return res;
    }
};
