class Solution {
public:
    bool valid (int i, int j, int n, int m) {
    if (i<0 || i>=n || j< 0|| j>=m)
        return false;
    return true;
}
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};
void dfs(vector<vector<char>>&a, int n, int m, int i, int j, vector<vector<bool>>&vis) {
    vis[i][j]=1;
    for (int k =0; k<4; k++) {
        int row = i + x[k];
        int col = j + y[k];
        if (valid(row, col, n, m) && vis[row][col]==false && a[row][col]=='1') {
            dfs(a, n, m, row, col, vis);
        }
    }
    return;
}
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int result = 0;
    vector<vector<bool>>vis(n);
    for (int i=0; i<n; i++) {
        vector<bool> temp(m, false);
        vis[i] = temp;
    }
    for (int i =0; i<n; i++) {
        for (int j =0; j< m; j++) {
            if (grid[i][j]=='1'&&vis[i][j]==false) {
                dfs(grid, n, m, i, j, vis);
                result++;
            }
        }
    }
    return result;
}
};