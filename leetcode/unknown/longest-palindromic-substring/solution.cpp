class Solution {
public:
int expand(const string& s, int left, int right) {
    while (left>=0 && right<s.size()&& s[left]==s[right]) {
        left--;right++;
    }
    return right- left-1;
}
string longestPalindrome(string s) {
    int n = s.size();
    int best_start = 0;
    int best_len =1;
    for (int i=0; i<n-1; i++) {
        int len1 = expand(s, i, i);
        int len = expand(s, i, i+1);
        int currMax = max(len1, len);
        if (currMax>best_len) {
            best_start = i - (currMax-1)/2;
            best_len = currMax;
        }
    }
    return s.substr(best_start, best_len);
}
};