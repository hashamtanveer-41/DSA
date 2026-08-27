class Solution {
public:
bool isPalindrome(string s) {
       int n = s.size();
    int left = 0, right = n-1;
    while (left<=right) {
        if (s[left]!=s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
    void palindromePartitions(vector<vector<string>>& res,const string& s,vector<string>& path, int start) {
    if (start ==s.size()) {
        res.push_back(path);
        return;
    }
    string temp = "";
    for (int end = start; end<s.size(); end++) {
        temp.push_back(s[end]);
        if (isPalindrome(temp)) {
            path.push_back(temp);
            palindromePartitions(res, s,path, end+1);
            path.pop_back();
        }
    }

}
vector<vector<string>> partition(string s) {
    int n = s.size();
    vector<vector<string>> res;
    vector<string> path;
    palindromePartitions(res, s, path, 0);
    return res;

}
};