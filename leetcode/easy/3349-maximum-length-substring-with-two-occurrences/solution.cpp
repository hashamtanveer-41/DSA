class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
    int left = 0, right =0;
    vector<int> characters(26, 0);
    int res =0;
    while (right<n) {
        characters[s[right]-'a']++;
        while (characters[s[right]-'a']>2) {
            characters[s[left]-'a']--;
            left++;
        }
        int windLen = right-left+1;
        res = max(windLen, res);
        right++;
    }
    return res;
    }
};