class MedianFinder {
private:
    priority_queue<double> left;
    priority_queue<double, std::vector<double>, greater<double> > right;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() && right.empty()){
            left.push(num);
            return;
        }
        int largestLeft = left.top();
        if(num > largestLeft){
            right.push(num);
        }
        else{
            left.push(num);
        }
        if(left.size() >= right.size() + 2){
            right.push(largestLeft);
            left.pop();
        }
        else if(right.size() >= left.size() + 2){
            int smallestRight = right.top();
            left.push(smallestRight);
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() > right.size()){
            return left.top();
        }
        else if(right.size() > left.size()){
            return right.top();
        }
        else{
            double l = left.top(), r = right.top();
            double ans = l;
            ans += r;
            ans /= 2;
            return ans;
        }
    }
};