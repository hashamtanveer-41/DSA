class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
    int open = 0;
    for (char c:  s) {
        if (c=='(')open++;
        else if (c==')') {
            res = max(res, open);
            open--;
        }
    }
    return res;
    }
};