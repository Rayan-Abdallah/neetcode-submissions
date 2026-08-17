/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    struct{
        bool operator()(Interval x, Interval y){
            if(x.start < y.start || (x.start == y.start && x.end < y.end)){
                return 1;
            }
            return 0;
        }
    } customLess;
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()){
            return 0;
        }
        sort(intervals.begin(), intervals.end(), customLess);
        multiset<int> roomEnd;
        roomEnd.insert(intervals[0].end);
        for(int i = 1; i < intervals.size(); i++){
            auto it = roomEnd.lower_bound(intervals[i].start);
            if(it == roomEnd.begin()){
                if(*it == intervals[i].start){
                    roomEnd.extract(it);
                }
                roomEnd.insert(intervals[i].end);
            }
            else{
                it--;
                roomEnd.extract(it);
                roomEnd.insert(intervals[i].end);
            }
        }
        return roomEnd.size();
    }
};
