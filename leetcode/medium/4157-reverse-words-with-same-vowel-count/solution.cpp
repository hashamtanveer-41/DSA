class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
    int reqVowel = 0, currVowel=0, start=0;
    for (int i =0; i< n; i++) {
        if (s[i]==' ') {
            // Word ended
            if (start==0) {
                // First Word ended
                reqVowel = currVowel;
            }else {
                if (currVowel==reqVowel) {
                    // I have to reverse
                    reverse(s.begin() + start, s.begin() + i);
                }
            }
            start = i+1;
            currVowel =0;
        }
        if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            currVowel++;
    }
    if (currVowel == reqVowel)reverse(s.begin()+start, s.end());
    return s;
    }
};