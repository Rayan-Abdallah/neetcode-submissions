class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<int> originalQ = queries;
        sort(queries.begin(), queries.end());
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        int intervalInd = 0;
        vector<int> res(queries.size());
        unordered_map<int, int> ans;
        for(int i = 0; i < queries.size(); i++) {
            while(intervalInd < intervals.size() && intervals[intervalInd][0] <= queries[i]){
                pq.push({intervals[intervalInd][1] - intervals[intervalInd][0] + 1, intervals[intervalInd][1]});
                intervalInd++;
            }
            while(!pq.empty() && pq.top().second < queries[i]){
                pq.pop();
            }
            if(!pq.empty()){
                ans[queries[i]] = pq.top().first;
            } else {
                ans[queries[i]] = -1;
            }
        }
        for(int i = 0; i < queries.size(); i++){
            res[i] = ans[originalQ[i]];
        }
        return res;
    }
};
