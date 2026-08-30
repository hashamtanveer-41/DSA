class MinStack {
public:
    vector<int> stack1;
    vector<int> stack2;

    MinStack() {

    }

    void push(int value) {
        if (stack1.empty()) {
            stack1.push_back(value);
            stack2.push_back(value);
        }else {
            stack1.push_back(value);
            int minVal = min(stack1.back(), stack2.back());
            stack2.push_back(minVal);
        }
    }

    void pop() {
        stack1.pop_back();
        stack2.pop_back();
    }

    int top() {
        return stack1.back();
    }

    int getMin() {
        return stack2.back();
    }
};



/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */