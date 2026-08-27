class Solution {
public:
bool result = false;
bool valid (int i, int j, int n, int m) {
    if (i<0 || i>=n || j< 0|| j>=m)
        return false;
    return true;
}
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};
    void findWord(vector<vector<char>>& board,int n, int m, int row, int col,int idx,string target) {
    if (idx==target.size()){result = true;return;}
    char val = board[row][col];
    board[row][col] = '*';
    for (int i=0; i<4; i++) {
        int r = row + x[i];
        int c = col + y[i];
        if (valid(r, c, n, m) && board[r][c]!='*' && board[r][c]==target[idx]) {
            findWord(board, n, m, r, c, idx+1, target);
        }
    }
    board[row][col] = val;
}
bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (board[i][j]==word[0])
                findWord(board, n, m,i, j, 1, word);
                if(result)return true;
        }
    }
    return false;;
}
};