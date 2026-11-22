class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
     int n = grid.size();
    int m = grid[0].size();
    int i=0, j=0;
    int row = i, col = j;
    vector<vector<int>> vis(n+1, vector<int>(m+1, -1));
    while (i<n&&j<m && i>=0 && j>=0) {
        if (vis[i][j]!=-1)break;
        char curr = grid[i][j];
        vis[i][j] = 1;
        if (curr=='L') {
            col = j, row = i;
            j--;
        }else if (curr=='R') {
            col = j, row = i;
            j++;
        }else if (curr=='U') {
            col = j, row = i;
            i--;
        }else {
            col = j, row = i;
            i++;
        }
    }
    return {row, col};
    }
};