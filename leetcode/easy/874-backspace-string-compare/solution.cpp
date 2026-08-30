class Solution {
public:
    bool backspaceCompare(string s, string t) {
    stack<char> st;
    for (char c: s)
        if (c!='#')
            st.push(c);
        else {
            if (!st.empty())
                st.pop();
        }


    s="";
    while (!(st.empty())) {
        s.push_back(st.top());
        st.pop();
    }

    for (char c: t)
        if (c!='#')
            st.push(c);
        else
            if (!st.empty())
                st.pop();


    t="";
    while (!(st.empty())) {
        t.push_back(st.top());
        st.pop();
    }
    bool equal = s.compare(t);
    return !equal;

}
};