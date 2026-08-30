class Solution {
public:
    int minAddToMakeValid(string s) {
    stack<char> st;
    int n = s.size();
    if (n==1)return 1;
    for (int i=0; i<n; i++) {
        if (st.empty()) {
            st.push(s[i]);
        }else {
            if (st.top()=='('&&s[i]==')') {
                st.pop();
            }else {
                st.push(s[i]);
            }
        }
    }
    return st.size();
}
};