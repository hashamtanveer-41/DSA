class Solution {
public:
    bool isSubsequence(string s, string t) {
        int required = 0;
    int m = s.size();
    int n = t.size();
    for (int i=0; i<n; i++) {
        if (required==m)return true;
        if (s[required]==t[i]) {
            required++;
        }
    }
    if (required==m)return true;
    return false;
    }
};