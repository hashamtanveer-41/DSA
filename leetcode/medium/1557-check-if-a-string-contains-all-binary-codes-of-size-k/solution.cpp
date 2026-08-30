class Solution {
public:
    bool hasAllCodes(string s, int k) {
    int n = s.size();
    unordered_map<string, int> freq;
    int val = pow(2, k);
    int left = 0, right = 0;
    string s1="";
    while (right<n) {
        if (s1.size()==k) {
            freq[s1]++;
            s1=s1.substr(1, k-1);
            left++;
        }
        s1+=s[right];
        right++;
    }
    freq[s1]++;
    if (freq.size()>=val)return true;
    return false;
}
};