class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0;
        sort(intervals.begin(), intervals.end());
        auto& curInterval = intervals[0];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < curInterval[1]){
                res++;
                if(intervals[i][1] < curInterval[1]){
                    curInterval = intervals[i];
                }
            }
            else{
                curInterval = intervals[i];
            }
        }
        return res;
    }
};
