class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
    stack<char> st;
    string res = "";
    for (int i=0; i<n; i++) {
        if (s[i]==']') {
            string temp ="";
            while (st.top()!='[') {
                temp.push_back(st.top());
                st.pop();
            }
            st.pop();
            string times = "";
            while (!st.empty() && st.top()!='[' && st.top()!=']' && !isalpha(st.top())) {
                times.push_back(st.top());
                st.pop();
            }
            reverse(times.begin(), times.end());
            reverse(temp.begin(), temp.end());
            int time = stoi(times);
            string temp1 = "";

            while (time--)
                temp1.append(temp);
            for (int j=0; j< temp1.size();j++)
                st.push(temp1[j]);
        }else {
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        res.push_back(st.top());st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
    }
};