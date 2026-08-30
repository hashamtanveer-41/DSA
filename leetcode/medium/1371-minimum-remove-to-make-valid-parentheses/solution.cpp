class Solution {
public:
    string minRemoveToMakeValid(string s) {
    int n = s.size();
    string res="";
    int open = 0;
    for (int i =0; i<n; i++) {
        if (s[i]=='(') {
            res.push_back(s[i]);
            open++;
        }else if (s[i]==')'){
            if (open>0) {
                open--;
                res.push_back(s[i]);
            }else{}
        }else {
            res.push_back(s[i]);
        }
    }
    if (open==0)return res;
    string res1="";
        for (int i =res.size()-1; i>=0; i--) {
            if (res[i]=='('&&open>0) {
                open--;
            }else {
                res1.push_back(res[i]);
            }
        }
    reverse(res1.begin(), res1.end());
    return res1;
}
};