class Solution {
public:
    bool isSafe(int row , int col, int n, vector<string>& matrix) {
    // Check for repetition in same column
    for (int i=0; i<matrix.size(); i++) {
        if (matrix[i][col]=='Q')return false;
    }
    // Check for validation in main Diagonal
    int i=row-1, j=col+1;
    while (i>=0 && j<n) {
        if (matrix[i][j]=='Q')return false;
        i--;j++;
    }
    // Check for validation in antidiagonal
    i=row-1, j=col-1;
    while (i>=0 && j>=0) {
        if (matrix[i][j]=='Q')return false;
        i--;j--;
    }
    return true;
}
void nQueens(vector<vector<string>>& res, vector<string>& temp,int row,  int n) {
    if (row==n) {
        res.push_back(temp);
        return;
    }
    for (int i=0; i<n; i++) {
        if (isSafe(row,i,n, temp)) {
            temp[row][i] = 'Q';
            // move on to next row
            nQueens(res, temp, row+1,  n);
            temp[row][i] = '.';
        }

    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> temp;
    string str = "";
    for (int i=0; i<n; i++) {
        str.push_back('.');
    }
    for (int i=0; i<n; i++) {
        temp.push_back(str);
    }
    nQueens(res, temp, 0,n);
    return res;
}
};