class Solution {
public:
bool isVowel(char ch) {
    return std::string("aeiouAEIOU").find(ch) != std::string::npos;
}
    string reverseVowels(string s) {
        int n = s.size();
    int left = 0, right = n-1;
    while (left<right) {
        if (!isVowel(s[left])) {
            left++;
        } else if (!isVowel(s[right])) {
            right--;
        }else {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    return s;
    }
};