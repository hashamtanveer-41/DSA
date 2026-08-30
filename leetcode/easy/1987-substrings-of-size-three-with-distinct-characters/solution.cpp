class Solution {
public:
    int countGoodSubstrings(string s) {
    int left = 0, mid =1, right = 2;
    int ans = 0;
    int n = s.size();
    while (right<n) {
        if (s[left]!=s[right]&&s[left]!=s[mid]&&s[right]!=s[mid]) {
            ans++;
        }
        left++;
        mid++;
        right++;
    }
    return  ans;

}
};