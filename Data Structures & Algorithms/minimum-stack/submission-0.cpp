class MinStack {
private:
    stack<int> s;
    vector<int> mn;
    int curInd = 0;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(curInd == 0){
            if(mn.empty()){
                mn.push_back(val);
            }
            else{
                mn[curInd] = val;
            }
        }
        else{
            if(curInd == mn.size()){
                mn.push_back(min(mn[curInd-1], val));
            }
            else{
                mn[curInd] = min(mn[curInd-1], val);
            }
        }
        curInd++;
    }
    
    void pop() {
        s.pop();
        curInd--;
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mn[curInd-1];
    }
};
