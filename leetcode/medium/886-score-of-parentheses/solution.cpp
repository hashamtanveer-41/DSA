class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
    int i = 0;
    stack<int> st;
    while (i<n) {
        if (s[i]=='(') {
           st.push(-1);
        }else {
            int val = 0;
           while (st.top()!=-1) {
               val += st.top();st.pop();
           }
            st.pop();
            if (val==0)val++;
            else val = val * 2;
            st.push(val);
        }
        i++;
    }
    int res = 0;
    while (!st.empty()) {
        res+=st.top(); st.pop();
    }
    return res;
    }
};