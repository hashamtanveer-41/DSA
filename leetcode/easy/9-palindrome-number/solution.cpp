class Solution {
public:
   long long int reverseNum(int num) {
    long long int res =0;
    while (num>0) {
        res = res*10+num%10;
        num /=10;
    }
    return res;
}bool isPalindrome(int x) {
    return x== reverseNum(x);
}
};