class Solution {
public:
    int largestInteger(int n, int s) {
        if (s>n*9) return -1;
    if (n==1)return s;
    int res =0;
    while (n--) {
        int diff = (s-9);
        if (diff<=0) {
            res = res*10+ s;
            s= 0;
        }
        else {
            res = res*10+ 9;
            s= s-9;
        }
    }
    return res;
    }
};