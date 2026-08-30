class Solution {
public:
    int prodDig (int n ) {
    int prod = 1;
    while (n>0) {
        prod *= n%10;
        n /= 10;
    }
    return prod;
}
int smallestNumber(int n, int t) {
    int lastDigit = n  % 10;
    if (lastDigit == 0)return n;
    for (int i = n; i<= (n+9); i++) {
        if (prodDig(i)%t==0)return i;
    }
    return n;
}
};