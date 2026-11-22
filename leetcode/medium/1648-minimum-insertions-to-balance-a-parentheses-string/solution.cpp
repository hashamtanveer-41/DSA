class Solution {
public:
    int minInsertions(string s) {
      int n = s.size();
    int res = 0;
    int open = 0;
    int i = 0;
    while (i<n) {
        char c = s[i];
        if (c=='(') {
            open++;
        }else {
            if (open==0) {
                // stack empty tells me that no open has ever came before so i need one open confirmed
                // and 1 or no close bracket
                if (i<n-1 && s[i+1]==')') {
                    res++;i++;
                }else if (i<n-1 && s[i+1]=='(') {
                    res+=2;
                }else if (i== n-1) {
                    // i am at last character which is close and i need 2 characters 1 open and 1 close
                    res+=2;
                }
            }else {
                if (i<(n-1) && s[i+1]==')')
                   {open--;i++;}
                else if (s[i+1]=='(') {
                    // stack not empty and its case of ()( so i need one insertion
                    res++;open--;
                }else if (i== n-1) {
                    // ) with last one and at top is (
                    res++;open--;
                }
            }
        }
        i++;
    }
    res += open*2;
    return res;
    }
};