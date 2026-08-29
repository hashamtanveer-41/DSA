class Solution {
public:

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.length();
    unordered_set<string> st(wordDict.begin(), wordDict.end());
    vector<bool> vis(n+1, false);
    vis[0] = true;
    for (int i =1; i<=n; i++) {
        for (int j = 0; j<i; j++) {
            if (vis[j] && st.count(s.substr(j, i-j))) {
                vis[i] = true;
                break;
            }
        }
    }
    return vis[n];}};