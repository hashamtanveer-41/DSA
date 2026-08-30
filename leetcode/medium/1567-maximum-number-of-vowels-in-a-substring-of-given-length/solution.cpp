class Solution {
public:
    int maxVowels(string s, int k) {
    int n = s.size();
    int left =0, right =0;
    int res = 0, temp = 0;
    while (right<n) {
        int windowSize = right-left+1;
        if (s[right]=='a'||s[right]=='e'||s[right]=='i'||s[right]=='o'||s[right]=='u') {
            temp++;
        }
        if (windowSize==k) {
            res = max(res, temp);
            if (s[left]=='a'||s[left]=='e'||s[left]=='i'||s[left]=='o'||s[left]=='u')
                temp--;
            left++;
        }
        right++;
    }
    return res;
}
};