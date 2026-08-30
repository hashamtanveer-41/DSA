class Solution {
public:
bool valid (int i, int j, int n, int m) {
    if (i<0 || i>=n || j< 0|| j>=m)
        return false;
    return true;
}
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};
    void dfsIV(vector<vector<char>>& a, int n, int m, int i, int j) {
    a[i][j] = '#';
    for (int k =0; k<4; k++) {
        int row = i+x[k];
        int col = j+y[k];
        if (valid(row, col, n, m)&&a[row][col]=='O')
            dfsIV(a, n, m, row, col);
    }
    return;
}
void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    int i, j;
    // 1st row
    for (j=0; j<m; j++)
        if (board[0][j]=='O')
            dfsIV(board, n,m , 0, j);
    // last row
    for (j=0; j<m; j++)
        if (board[n-1][j]=='O')
            dfsIV(board, n,m , n-1, j);
    // 1st col
    for (i=0; i<n; i++)
        if (board[i][0]=='O')
            dfsIV(board, n,m , i, 0);
    // Last col
    for (i=0; i<n; i++)
        if (board[i][m-1]=='O')
            dfsIV(board, n,m , i, m-1);
    // Replace the characters
    for (i=0; i< n; i++) {
        for (j=0; j<m; j++) {
            if (board[i][j]=='#')
                board[i][j]='O';
            else
                board[i][j]='X';
        }
    }
}
};