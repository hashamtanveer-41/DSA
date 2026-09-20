class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
    int n = path.size();
    for (int i=0;i<n; i++) {
        if (path[i] == '/')continue;
        string token = "";
        while (i<n && path[i]!='/') {
            token += path[i];
            i++;
        }
        if (token == ".") {
            continue;
        }else if (token == "..") {
            if(!st.empty() )st.pop_back();
        }else {
            st.push_back(token);
        }
    }
    if (st.empty())return "/";
    string res = "";
    for (const string& dir: st) {
        res += "/" + dir;
    }
    return res;
    }
};