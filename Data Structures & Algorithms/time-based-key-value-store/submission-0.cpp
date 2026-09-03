class TimeMap {
unordered_map<string, set<int> > mp;
unordered_map<int, string> timeToVal;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert(timestamp);
        timeToVal[timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = upper_bound(mp[key].begin(), mp[key].end(), timestamp);
        if(it == mp[key].begin()){
            return "";
        }
        it--;
        return timeToVal[*it];
    }
};
