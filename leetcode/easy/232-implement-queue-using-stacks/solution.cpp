class MyQueue {
public:
    stack<int> org;
    stack<int> copy;
    MyQueue() {
        
    }
    
    void push(int x) {
        org.push(x);
    }
    
    int pop() {
        while(!org.empty()){
            copy.push(org.top());
            org.pop();
        }
        int req = copy.top();
        copy.pop();
        while(!copy.empty()){
             org.push(copy.top());
            copy.pop();
        }
        return req;
    }
    
    int peek() {
        while(!org.empty()){
            copy.push(org.top());
            org.pop();
        }
        int req = copy.top();
        while(!copy.empty()){
             org.push(copy.top());
            copy.pop();
        }
        return req;
    }
    
    bool empty() {
        return org.empty();
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