class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n==1)return s;
    long long pairs = n/2;
    return s+ m*(pairs) -(pairs -1);
    }
};