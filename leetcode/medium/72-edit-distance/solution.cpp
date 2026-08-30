class Solution {
public:
    int findMinDist(string word1, string word2,int i,int j, vector<vector<int>>& dp) {
    // Base case
    if (i==word1.size()) {
        // am i still left with j's
        // return how much are left cuz you will have to insert those character
        return word2.size()-j;
    }
    if ( j== word2.size()) {
        // Word 2 ended it means i am done and check am i still left with i's if yes then we willhave to remove them
        return word1.size()-i;
    }
    if (dp[i][j]!=-1)return dp[i][j];
    if (word1[i]==word2[j]) {
       return dp[i][j] = findMinDist(word1, word2, i+1, j+1, dp);
    }else {
        // Deletion
        int c1 = 1+ findMinDist(word1, word2, i+1, j ,dp);
        // Insert
        int c2 =1+  findMinDist(word1, word2, i, j+1, dp);
        // Replace
        int c3 = 1+ findMinDist(word1, word2,i+1, j+1 ,dp);
        return dp[i][j] =  min (c1, min(c2, c3));
    }
}
int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n);
    for (int i = 0; i<n; i++) {
        vector<int>t(m+1, -1);
        dp[i] = t;
    }
    return findMinDist(word1, word2, 0, 0, dp);
}
};