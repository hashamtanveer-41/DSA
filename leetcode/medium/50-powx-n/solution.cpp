class Solution {
public:
    double fun4(double x, int n) {
    if (n==1)return x;
    double left = fun4(x, n/2);
    return n%2==0? left * left:fun4(x, n/2+1) * left;
}
double fun5(double x, int n) {
    if (n==-1)return 1/x;
    double left = fun5(x, n/2);
    return n%2==0?
        left
    *
        left
    :
        fun5(x, n/2-1)
    *
        left;
}
double myPow(double x, int n) {
    if (n==0)return 1;
    double res = n<0? fun5(x,n):fun4(x, n);
    return res;
}
};