class Solution {
public:
    int longestValidParentheses(string s) {
    int n = s.size();
    stack<int> st;
    vector<bool> is(n, false);
    for (int i=0; i<n; i++) {
        char curr = s[i];
        if (curr=='(') {
            st.push(i);
        }
        else if (curr==')' && !st.empty()) {
            is[i] = true;
            is[st.top()] = true;
            st.pop();
        }
    }
    int res = 0;
    // Now i need the longest window with most true
    int low = 0, high = 0;
    while (high<n) {
        if (is[high]==false)
            low = high +1;
        res = max(res, high - low +1);
        high++;
    }
    return res;
}
};