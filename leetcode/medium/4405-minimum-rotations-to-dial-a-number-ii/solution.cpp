class Solution {
public:
    int getDist(int from, int curr) {
        int c1 = abs(curr - from);
        int c2 = abs(from + 10 - curr);
        int c3 = abs(10 - from + curr);
        return min({c1, c2, c3});
    }
int minRotations(int n, string s) {

      long long total = 0;
    int prev = 0;
    for (int i = 0; i<n ; i++) {
        int curr = s[i] - '0';
        total +=getDist(curr, prev);
        prev = s[i] - '0';
    }
    int res = total;
    for (int i=0; i<n; i++) {
        int cut = i == 0? 0: s[i-1] - '0';
        int old = s[i] - '0';
        int newTar = s[n-1] - '0';
        int candidate = total - getDist(cut, old) + getDist(cut, newTar);
        res = min(res, candidate);
    }

    return res;
}
};