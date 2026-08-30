class Solution {
public:
    bool isPalindrome(string s) {
    string temp = "";
    int n = s.size();
    for (int i=0; i< s.size();i++ ) {
        if (isalnum(s[i])) {
            temp.push_back(tolower(s[i]));
        }
    }
    n = temp.size();
    int left = 0, right = n-1;
    while (left<=right) {
        if (temp[left]!=temp[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

    bool isPalindromic(string s) {
       string res = "";
    for(char c : s){
        bitset<8> st(c);
        res.append(st.to_string());
    }
    return isPalindrome(res);
    }
};