class Solution {
public:
    string convert(string s, int numRows) {
         int n = s.size();
         if(numRows==1)return s;
    string res = "";
    int start = 0;
    int cycle = 2 * (numRows - 1);
    while (start<numRows) {
        int i = start;
        int jump1 = cycle - 2* start;
        int jump2 = 2 * start;
        if (jump1==0)
            jump1 = jump2;
        if (jump2==0)
            jump2 = jump1;
        bool is = true;
        while (i < n) {
            if (is) {
                res.push_back(s[i]);
                is = false;
                i += jump1;
            }else {
                res.push_back(s[i]);
                is = true;
                i+=jump2;
            }
        }
        start++;
    }
    return res;
    }
};