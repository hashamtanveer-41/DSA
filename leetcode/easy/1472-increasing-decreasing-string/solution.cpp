class Solution {
public:
    string sortString(string s) {
    int n = s.size();
    vector<int> freq(26, 0);
    for (char c: s)freq[c-'a']++;
    string res = "";
    
    while (res.size()!=n) {
        for (int i=0; i<26; i++) {
            if (freq[i]>0) {
                res.push_back(i+'a');
                freq[i]--;
            }
        }
        for (int i=25; i>=0; i--) {
            if (freq[i]>0) {
                res.push_back(i+'a');
                freq[i]--;
            }
        }
    }
    return res;
}

};