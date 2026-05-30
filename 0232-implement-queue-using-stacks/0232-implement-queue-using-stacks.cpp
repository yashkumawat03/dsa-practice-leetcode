class MyQueue {
    stack<int> st1;
    stack<int> st2;
public:
    MyQueue() {
        
    }
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int x;
        if(!st2.empty()){
            x = st2.top();
            st2.pop();
        }
        // If the stack is empty
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            x = st2.top();
            st2.pop();
        }
        return x;
    }
    
    int peek() {
        if(!st2.empty()){
            return st2.top();
        }
        // stack 2 is empty
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */