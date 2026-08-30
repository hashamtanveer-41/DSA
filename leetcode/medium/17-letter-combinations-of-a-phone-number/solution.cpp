class Solution {
public:
    void func1(string&s,unordered_map<char, string> f,int n, int idx, string diary, vector<string>& res) {
    if (idx == n) {
        res.push_back(diary);
        return;
    }
    string choice = f[s[idx]];
    for (int i =0; i<choice.size(); i++) {
        diary.push_back(choice[i]);
        func1(s, f, n, idx+1, diary, res);
        diary.pop_back();
    }
    return;
}
vector<string> letterCombinations(string digits) {
    unordered_map<char, string> f;
    f['2'] = "abc";
    f['3'] = "def";
    f['4'] = "ghi";
    f['5'] = "jkl";
    f['6'] = "mno";
    f['7'] = "pqrs";
    f['8'] = "tuv";
    f['9'] = "wxyz";
    string diary ="";
    vector<string> res;
    int n= digits.size();
    int idx = 0;
    func1(digits,f, n,idx, diary,  res);
    return res;
}
};