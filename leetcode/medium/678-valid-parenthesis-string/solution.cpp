class Solution {
public:
  bool checkStringValidity(string s, int open, int i, int n,vector<vector<int>>& dp ) {
    if (open<0)return false;
    if (i == n) {
        if (open==0)
            return true;
        return false;
    }
    if (dp[i][open]!=-1)
        return dp[i][open];
    char curr = s[i];
    if (curr=='(') {
       return dp[i][open] = checkStringValidity(s, open+1, i+1, n, dp);
    }else if (curr==')') {
       return dp[i][open] = checkStringValidity(s, open-1, i +1, n, dp);
    }else {
      return dp[i][open] = checkStringValidity(s, open, i+1, n, dp)
       || checkStringValidity(s, open+1, i+1, n,dp)
       || checkStringValidity(s, open-1, i+1, n, dp);
    }
}
bool checkValidString(string s) {
   int high = 0;
    int low = 0;
    for (char c: s) {
        if (c=='(') {
            high++;
            low++;
        }else if (c==')') {
            high--;
            low--;
        }else {
            high++;
            low--;
        }
        if (high<0)
            return false;
        low = max(0, low);
    }
    return low == 0;
}
};