class MedianFinder {
private:
    multiset<double> left, right;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty()&&right.empty()){
            left.insert(num);
            return;
        }
        auto it = left.end();
        it--;
        if(num > *it){
            right.insert(num);
        }
        else{
            left.insert(num);
        }
        if(left.size() >= right.size() + 2){
            right.insert(*it);
            left.erase(left.find(*it));
        }
        else if(right.size() >= left.size() + 2){
            it = right.begin();
            left.insert(*it);
            right.erase(right.find(*it));
        }
    }
    
    double findMedian() {
        if(left.size() > right.size()){
            auto it = left.end();
            it--;
            return *it;
        }
        else if(right.size() > left.size()){
            return *right.begin();
        }
        else{
            auto it = left.end();
            it--;
            double l = *it, r = *right.begin();
            double ans = l;
            ans += r;
            ans /= 2;
            return ans;
        }
    }
};
