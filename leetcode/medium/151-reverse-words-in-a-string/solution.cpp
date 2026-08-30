class Solution {
public:
    string reverseWords(string s) {
        while (s[0]==' ')
        s.erase(0, 1);
    while (s[s.size()-1]==' ')
        s.erase(s.size()-1, 1);
    reverse(s.begin(), s.end());
    int read =0;
    int write =0;
    while (read<s.size()){
        if (s[read]==' ' && read> 0 && s[read-1]==' ') {
            // Invalid
        }else {
            // Valid
            s[write]=s[read];
            write++;
        }
        read++;
    }
    s.resize(write);
    int n = s.size();
    int start = 0;
    for (int i=0; i<n; i++) {
        if (s[i]==' ') {
            reverse(s.begin()+start, s.begin()+i);
            start =i+1;
        }
    }
        reverse(s.begin()+start, s.end());

    return s;
    }
};