class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = -1, end = -1;
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] <= newInterval[0]){
                start = i;
            }
            if(intervals[i][1] >= newInterval[1] && end == -1){
                end = i;
            }
        }
        vector<vector<int> > res;
        for(int i = 0; i < start; i++){
            res.push_back(intervals[i]);
        }
        if(start != -1){
            res.push_back(intervals[start]);
            if(intervals[start][1] < newInterval[0]){
                res.push_back(newInterval);
            }
            if(end != -1){
                if(intervals[end][0] > newInterval[1]){
                    res[res.size() - 1][1] = max(intervals[end - 1][1], newInterval[1]);
                    res.push_back(intervals[end]);
                }
                else{
                    res[res.size() - 1][1] = intervals[end][1];
                }
                for(int i = end + 1; i < intervals.size(); i++){
                    res.push_back(intervals[i]);
                }
            }
            else{
                res[res.size() - 1][1] = newInterval[1];
            }
        }
        else{
            res.push_back(newInterval);
            if(end != -1){
                if(intervals[end][0] > newInterval[1]){
                    res.push_back(intervals[end]);
                }
                else{
                    res[res.size() - 1][1] = intervals[end][1];
                }
                for(int i = end + 1; i < intervals.size(); i++){
                    res.push_back(intervals[i]);
                }
            }
        }
        return res;
    }
};
