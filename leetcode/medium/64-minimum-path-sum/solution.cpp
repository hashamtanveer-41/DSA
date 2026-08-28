class Solution {
public:
bool valid (int i, int j, int n, int m) {
    if (i<0 || i>=n || j< 0|| j>=m)
        return false;
    return true;
}
    int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> adj(n);
    for (int i=0; i<n; i++) {
        vector<int> t(m, INT_MAX);
        adj[i] = t;
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    adj[0][0] = grid[0][0];
    int x[2] = {1, 0};
    int y[2] = {0, 1};
    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        int row = p.first;
        int column = p.second;
        int val = adj[row][column];
        for (int i=0; i<2; i++) {
            int r  = row + x[i];
            int c= column + y[i];
            if (!valid(r, c, n, m))continue;
            int newSum = val + grid[r][c];
            if (newSum<adj[r][c]) {
                adj[r][c] = newSum;
                q.push({r, c});
            }
        }
    }
    return adj[n-1][m-1];
}
};