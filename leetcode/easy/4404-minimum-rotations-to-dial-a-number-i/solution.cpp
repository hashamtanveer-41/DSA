class Solution {
public:
    int minRotations(string s) {
          int n = s.size();
    int from = 0;
    int res = 0;
    for (int i=0; i<n; i++) {
        int curr = s[i] - '0';
        int c1 = abs(curr - from);
        int c2 =abs( from+10-curr);
        int c3 = abs(10-from + curr);
        from = curr;
        res += min({c1,c2, c3 });
    }
    return res;
    }
};