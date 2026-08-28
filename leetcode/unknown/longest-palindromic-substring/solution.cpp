class Solution {
public:
bool isPalindrome(const string& s) {
    int n = s.size();
    int left = 0, right = n-1;
    while (left<right) {
        if (s[left]!=s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
   string longestPalind = "";
void findLongesPalindrome(const string& s, int start,vector<int>& vis ) {
    if (start==s.size())return;
    if (vis[start]==1)return;
    string temp = "";
    vis[start] = 1;
    for (int i= start;i<s.size(); i++) {
        temp.push_back(s[i]);
        if ( isPalindrome(temp) && (temp.size()>longestPalind.size())) {
            longestPalind = temp;
        }
        if (vis[i]==-1)
            findLongesPalindrome(s, i, vis);
    }
}
string longestPalindrome(string s) {
    vector<int> vis(s.size(), -1);
    findLongesPalindrome(s, 0, vis);
    return longestPalind;
}
};