class Solution {
public:
bool valid (int i, int j, int n, int m) {
    if (i<0 || i>=n || j< 0|| j>=m)
        return false;
    return true;
}
bool dfs(int i, int j,int n, int m, vector<vector<int>>& grid) {
    if (!valid(i, j, n, m))return false;
    if (grid[i][j]==1)
        return true;
    grid [i][j] = 1;
    bool left = dfs(i, j-1, n, m, grid);
    bool right = dfs(i, j+1, n, m, grid);
    bool top = dfs(i-1, j, n, m, grid);
    bool bottom = dfs(i+1, j, n, m, grid);
    return left && right && top && bottom;
}
int closedIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    int res = 0;
    for(int i=1; i<n-1; i++){
        for(int j=1; j<m-1; j++){
           if (grid[i][j]==0) {
               if (dfs(i, j,n, m, grid)) {
                   res++;
               }
           }
        }
    }
    return res;
}
};