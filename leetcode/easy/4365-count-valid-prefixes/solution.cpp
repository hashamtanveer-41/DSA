class Solution {
public:
    int countValidPrefixes(string s) {
       int ones =0, zeros = 0, res = 0;
    for (char c : s) {
        if (c == '1' ) {
            ones++;
        }else {
            zeros++;
        }
        int diff = abs(zeros-ones);
        if (diff<=1)res++;
    }
    return res; 
    }
};