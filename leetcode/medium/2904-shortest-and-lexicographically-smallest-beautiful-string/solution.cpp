class Solution {
public:
   string shortestBeautifulSubstring(string s, int k) {
    int n = s.size();
    int left = 0, right = 0, res = n;
    int start  = 0;
    while (right<n) {
        if (s[right]=='1')k--;
        while (k<0 || s[left]=='0') {
            if (s[left]=='1')k++;
            left++;
        }
        if (k==0) {
            int windLen = right - left +1;
            if (windLen<res) {
                res = windLen;
                start = left;
            }else if (windLen == res) {
                if (s.compare(left, windLen, s, start, res) < 0) {
                    res = windLen;
                    start = left;
                }
            }
        }
        right++;
    }
    if(k>0)return "";
    return s.substr(start, res);
}
};