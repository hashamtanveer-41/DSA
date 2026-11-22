class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
    string res = "";
    for (char c: s) {
        if (c=='(') {
            if (open>0)res+=c;
            open++;
        }else {
             open--;
            if (open>0)res+=c;
        }
    }
    return res;
    }
};