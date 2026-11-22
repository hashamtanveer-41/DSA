class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
      int n = seq.size();
    vector<int> res(n, 0);
    int a = 0;
    int b = 0;
    for (int i=0; i<n; i++) {
        char curr = seq[i];
        if (curr=='(') {
            if (a<=b) {
                a++;
                res[i] = 0;
            }else {
                b++;
                res[i] = 1;
            }
        }else {
            if (a!=0 && a>=b) {
                a--;
                res[i] = 0;
            }else {
                b--;
                res[i] = 1;
            }
        }
    }
    return res;}
};