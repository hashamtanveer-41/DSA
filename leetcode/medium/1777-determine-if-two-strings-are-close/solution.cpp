class Solution {
public:
    bool closeStrings(string word1, string word2) {
       int n = word1.size();
    int m = word2.size();
    if(n != m )return false;
    unordered_map<char, int> freq1;
    unordered_map<char, int> freq2;
    for (char c: word1)freq1[c]++;
    for (char c: word2)freq2[c]++;
    vector<int> w1;
    vector<int> w2;
    for (auto& a: freq1)
        w1.push_back(a.second);
    for (auto& a: freq2) {
        if (freq1.find(a.first)==freq1.end())return false;
        w2.push_back(a.second);
    }
    sort(w1.begin(), w1.end());
    sort(w2.begin(), w2.end());
    bool res =  w1 == w2;
    return res;
    }
};