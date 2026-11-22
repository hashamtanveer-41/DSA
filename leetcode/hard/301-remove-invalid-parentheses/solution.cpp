class Solution {
public:
   int minVal = INT_MAX;
unordered_set<string> set;
void removalInvalidBrackets(const string& s, int n, int i, string& temp, vector<string>& res, int open){
    if (i==n) {
        int removals = n - temp.size();
        if (open==0 && removals<=minVal) {
            if (removals<minVal) {
                res = {};
                minVal = removals;
                set.clear();
            }
            if (set.count(temp)==0) {
                res.push_back(temp);
                set.insert(temp);
            }
        }
        return;
    }
    char curr = s[i];
    if (curr=='(') {
        temp.push_back(curr);
        removalInvalidBrackets(s, n, i+1, temp, res, open+1);
        temp.pop_back();
        removalInvalidBrackets(s, n, i+1, temp, res, open);
    }else if (curr==')') {
        if (open>0) {
            temp.push_back(curr);
            removalInvalidBrackets(s, n, i+1, temp, res, open-1);
            temp.pop_back();
            removalInvalidBrackets(s, n, i+1, temp, res, open);
        }else if (open==0) {
            removalInvalidBrackets(s, n, i+1, temp, res, open);
        }
    }else {
        temp.push_back(curr);
        removalInvalidBrackets(s, n, i+1, temp, res, open);
        temp.pop_back();
    }
}
vector<string> removeInvalidParentheses(string s) {
    int n = s.size();
    string temp = "";
    vector<string> res;
    removalInvalidBrackets(s, n, 0, temp, res, 0);
    return res;
}
};