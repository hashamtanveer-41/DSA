class Solution {
public:
    long long countCommas(long long n) {
       long long threshold = 1000, res = 0;
    while (n>=threshold) {
        res += n- threshold +1;
        threshold *= 1000;
    }
    return res;
    }
};