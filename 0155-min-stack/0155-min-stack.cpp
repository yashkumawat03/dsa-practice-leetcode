class MinStack {
public:
    stack<long long> st; // all elements insert
    long long min = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            min = val;
        }
        else{
            if(val >= min){
                st.push(val);
            }
            else{
                st.push(2LL * val - min);
                min = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        else{
            long long x = st.top();
            st.pop();
            if(x < min){
                min = 2 * min - x;
            }
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        else{
            long long x = st.top();
            if(x >= min) return (int)x;
            else{
                return (int)min;
            }
        }
    }
    
    int getMin() {
        if(st.empty()) return -1;
        else{
            return (int)min;
        }

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