class MinStack {
private:
    stack<int> s;
    stack<int> mn;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(mn.empty()){
            mn.push(val);
        }
        else{
            mn.push(min(mn.top(), val));
        }
    }
    
    void pop() {
        s.pop();
        mn.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mn.top();
    }
};
