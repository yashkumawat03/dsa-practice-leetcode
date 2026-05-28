class MinStack {
public:
    stack<int> st1; // all elements insert
    stack<int> minstck; // 
    MinStack() {
        
    }
    
    void push(int val) {
        if(st1.size() == 0){
            st1.push(val);
            minstck.push(val);
        }
        else{
            st1.push(val);
            if(val <= minstck.top()){
                minstck.push(val);
            }
        }
    }
    
    void pop() {
        if(st1.size()==0)
            return;
        if(minstck.top()==st1.top()) {
            minstck.pop();
        }
        st1.pop();
    }
    
    int top() {
        if(st1.size() == 0 ) {
            return -1;
        }

        return st1.top();
    }
    
    int getMin() {
        if(minstck.size()==0) {
            return -1;
        }

        return minstck.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */