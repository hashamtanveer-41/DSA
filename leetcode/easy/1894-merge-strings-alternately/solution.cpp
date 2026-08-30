class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
    int m = word2.size();
    string res = "";
    int i =0;
    while (i<n || i<m) {
        if (i<n)res.push_back(word1[i]);
        if (i<m)res.push_back(word2[i]);
        i++;
    }
    return res;
    }
};