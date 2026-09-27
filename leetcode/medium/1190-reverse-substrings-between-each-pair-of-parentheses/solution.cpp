class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
    stack<int> st;
    for (int i=0; i<n; i++) {
        char curr = s[i];
        if (curr=='(') {
            st.push(i);
        }else if (curr==')') {
            int idx = st.top();
            st.pop();
            reverse(s.begin()+ idx, s.begin()+i);
        }
    }
    string res = "";
    for (char c: s) {
        if (c == ')' || c== '(')continue;
        res.push_back(c);
    }
    return res;
    }
};