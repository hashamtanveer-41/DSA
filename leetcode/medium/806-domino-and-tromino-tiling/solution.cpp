class Solution {
public:
    int numTilings(int n) {
    int MOD = 1e9 +7;
    if (n==1||n==2)return n;
    int prev_prev = 2;
    int prev_prev_prev = 1;
    int prev = 5;
    for (int i =4; i<=n; i++) {
        int sum =(((prev % MOD) * 2)% MOD + prev_prev_prev)%MOD;
        prev_prev_prev = prev_prev;
        prev_prev = prev;
        prev = sum;
    }
    return prev;
}
};