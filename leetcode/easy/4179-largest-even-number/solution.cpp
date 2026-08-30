class Solution {
public:
    string largestEven(string s) {
       int n = s.length();
    for (int i = n-1; i>=0; i--) {
        if (s[i]=='1')s.pop_back();
        else return s;
    }
    return s;
    }
};