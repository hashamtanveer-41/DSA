class Solution {
public:
    string makeGood(string s) {
    int n = s.size();
    if (n==0||n==1)return s;
    vector<char> st;
    for (int i=0; i<n; i++) {
        if (!st.empty()&&s[i]!=st.back()&&tolower(s[i])==tolower(st.back())) {
            st.pop_back();
            // i=i+1;
            continue;
        }
        st.push_back(s[i]);
    }
    s="";
    while (!st.empty()) {
        s.push_back(st.back());
        st.pop_back();
    }
    reverse(s.begin(), s.end());
    return s;
}
};