class LRUCache {
private:
    unordered_map<int, int> mp;
    unordered_map<int, int> t;
    queue<int> q;
    int curIndInQ = 0;
    int curTime = 0;
    int cap = 0;
    int curSize = 0;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!mp.contains(key)){
            return -1;
        }
        if(mp[key] != -1){
            t[key] = curTime;
            curTime++;
            q.push(key);
        }
        return mp[key];
    }
    
    void put(int key, int value) {
        t[key] = curTime;
        curTime++;
        q.push(key);
        if(!mp.contains(key) || (mp.contains(key) && mp[key] == -1)){
            curSize++;
        }
        mp[key] = value;
        if(curSize > cap){
            curSize--;
            while(true){
                int cur = q.front();
                q.pop();
                if(t[cur] == curIndInQ){
                    curIndInQ++;
                    mp[cur] = -1;
                    break;
                }
                curIndInQ++;
            }
        }
    }
};
