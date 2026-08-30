class Solution {
public:
    void func11(int n, int k, int i, int cost, vector<string>&res, string& temp) {
    if (i==n) {
        if (cost<=k)
            res.push_back(temp);
        return;
    }
    if (cost>k)return;
    if (!temp.empty() && temp.back()=='1') {
        temp.push_back('0');
        func11(n, k, i+1, cost, res, temp);
        temp.pop_back();
    }else {
        temp.push_back('0');
        func11(n, k, i+1, cost, res, temp);
        temp.pop_back();
        temp.push_back('1');
        func11(n, k, i+1, cost+i, res, temp);
        temp.pop_back();
    }
}
vector<string> generateValidStrings(int n, int k) {
    vector<string> res;
    string temp="";
    func11(n, k, 0, 0,res, temp);
    return res;
}
};