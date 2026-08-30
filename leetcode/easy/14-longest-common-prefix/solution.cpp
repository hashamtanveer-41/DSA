class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
    if (n==1)return strs[0];
    string res = "";
    int idx = 0;
    while (true) {
        for (int i =0; i< n; i++) {
            if (idx==strs[i].size()) {
                if (i>0) 
                    res.pop_back();
                return res;
            }
            if (i==0)res.push_back(strs[i][idx]);
            if (res[idx]!=strs[i][idx]) {
                res.pop_back();
                return res;
            }
        }
        idx++;
    }
    }
};