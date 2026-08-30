class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    stack<int>st;
    st.push(stoi(tokens[0]));
    int ptr = 1;
    while (ptr<tokens.size()) {
        if (tokens[ptr]=="*") {
            int val1 = (st.top());
            st.pop();
            int val2 = (st.top());
            st.pop();
            st.push((val1*val2));
        }else if (tokens[ptr]=="/") {
            int val1 = (st.top());
            st.pop();
            int val2 = (st.top());
            st.pop();
            st.push((val2/val1));
        }else if (tokens[ptr]=="+") {
            int val1 = (st.top());
            st.pop();
            int val2 = (st.top());
            st.pop();
            st.push((val1+val2));
        }else if (tokens[ptr]=="-") {
            int val1 = (st.top());
            st.pop();
            int val2 = (st.top());
            st.pop();
            st.push((val2-val1));
        }else {
            st.push(stoi(tokens[ptr]));
        }
        ptr++;
    }
    return st.top();
}
};