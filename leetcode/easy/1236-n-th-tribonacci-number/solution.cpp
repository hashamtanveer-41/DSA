class Solution {
public:
    int tribonacci(int n) {
        if (n==0)return n;
    if (n<3)return 1;
    int first = 1;
    int second = 1;
    int third = 0;
    for (int i=3; i<=n; i++) {
        int sum = first +second + third;
        third = second;
        second = first;
        first = sum;
    }
    return first;
    }
};