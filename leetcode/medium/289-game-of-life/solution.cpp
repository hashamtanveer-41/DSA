class Solution {
public:
    bool valid (int i, int j, int n, int m) {
    if (i<0 || i>=n || j< 0|| j>=m)
        return false;
    return true;
}
void gameOfLife(vector<vector<int>>& board) {
    int n = board.size();
    int m = board[0].size();
    int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[8] = {-1, 0, 1, -1, 1, -1, 0 ,1} ;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            //
            bool alive = board[i][j];
            int count = 0;
            // first check that how many alive neighbours it has
            for (int k= 0; k<8; k++) {
                int r = i + x[k];
                int c = j+ y[k];
                if (valid(r, c, n, m)) {
                    if (board[r][c]==1 || board[r][c]==2)count++;
                }
            }
            if (alive) {
                if (count<2 || count >3) {
                    // Cell dies
                    board[i][j] = 2;
                }
            }else {
                if (count == 3) {
                    // it becomes alive
                    board[i][j] = -1;
                }
            }
        }
    }
    for (int i =0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (board[i][j]==2)
                board[i][j] = 0;
            else if (board[i][j]==-1)
                board[i][j] = 1;
        }
    }
}
};